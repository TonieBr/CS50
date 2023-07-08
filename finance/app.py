import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Allows to use functions within templates (not the most elegant method)
app.jinja_env.globals.update(lookup=lookup)

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
@login_required
def index():
    """Show portfolio of stocks"""

    if request.method == "POST":
        try:
            money = request.form.get("money")
        except ValueError:
            return apology("Please enter a valid amount")

        if not money or int(money) < 0:
            return apology("Please enter a valid amount")

        # balance
        balance = db.execute("SELECT cash FROM users WHERE id= ?", session["user_id"])
        db.execute("UPDATE users SET cash=? WHERE id = ?", balance[0]['cash'] + int(money), session["user_id"])

        return redirect("/")

    else:
        portfolio = db.execute(
            "SELECT amount, symbol, cash FROM users JOIN stocks on id = user_id WHERE id = ?", session["user_id"])
        if not portfolio:
            return render_template("indexempty.html")

        cash = portfolio[0]['cash']
        counter = 0
        for row in portfolio:
            counter = counter + (lookup(row['symbol']))['price'] * row['amount']

        return render_template("index.html", cash=cash, portfolio=portfolio, counter=counter)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")

        try:
            shares = int(request.form.get("shares"))
        except ValueError:
            return apology("Please enter a valid amount")

        if not symbol or not shares or shares < 0:
            return apology("Please enter a valid amount")

        # balance
        balance = db.execute("SELECT cash FROM users WHERE id= ?", session["user_id"])

        # Price of stocks
        priceStock = lookup(symbol)
        if not priceStock:
            return apology("No stocks found")

        if (priceStock['price'] * shares) > balance[0]['cash']:
            return apology("Not enough balance")

        rows = db.execute("SELECT symbol FROM stocks WHERE symbol = ? AND user_id = ?", symbol, session["user_id"])
        if len(rows) != 1:
            db.execute("INSERT INTO stocks (user_id, symbol, amount) VALUES (?, ?, ? )", session["user_id"], symbol, shares)
        else:
            currentAmount = db.execute("SELECT amount FROM stocks WHERE symbol = ?", symbol)
            db.execute("UPDATE stocks SET amount=? WHERE user_id =? AND symbol =?",
                       (currentAmount[0]['amount'] + shares), session["user_id"], symbol)

        db.execute("UPDATE users SET cash=? WHERE id = ?", balance[0]['cash'] - priceStock['price']*int(shares), session["user_id"])

        # LOG
        try:
            db.execute("INSERT INTO history (user_id, trant, trand, price, trana) VALUES (?, ?, DATE('now'), ?, ?)",
                       session["user_id"], "BUY", (lookup(symbol[0]))['price'], shares)
        except Exception:
            return redirect("/")

        return redirect("/")

    else:
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    data = db.execute(
        "SELECT * FROM users JOIN stocks on id = stocks.user_id JOIN history on id = history.user_id WHERE id = ?", session["user_id"])

    return render_template("history.html", data=data)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")

        if not symbol:
            return apology("Please enter a valid amount")
        symbol = request.form.get("symbol")
        data = lookup(symbol)
        if not data:
            return apology("No stocks found")
        return render_template("quoted.html", data=data)

    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")

        if not username or not password:
            return apology("Please enter username and password")
        if password != confirmation:
            return apology("Passwords do not match")

        rows = db.execute("SELECT username FROM users WHERE username= (?)", username)
        if rows:
            return apology("User already exists")

        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", username, generate_password_hash(password))
        return redirect("/")

    else:
        return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")

        if not symbol or not shares:
            return apology("Please enter a valid amount")

        # currentAmount
        currentAmount = db.execute("SELECT amount FROM stocks WHERE user_id = ?", session["user_id"])
        if int(currentAmount[0]['amount']) < 0 or int(currentAmount[0]['amount']) < int(shares):
            return apology("Not enough shares")

        # balance
        balance = db.execute("SELECT cash FROM users WHERE id= ?", session["user_id"])

        # Price of stocks
        priceStock = lookup(symbol)

        db.execute("UPDATE stocks set amount=? WHERE user_id = ? AND symbol= ?", int(
            currentAmount[0]['amount']) - int(shares), session["user_id"], symbol)
        db.execute("UPDATE users SET cash=? WHERE id = ?", balance[0]['cash'] + priceStock['price']*int(shares), session["user_id"])

        # LOG
        try:
            db.execute("INSERT INTO history (user_id, trant, trand, price, trana) VALUES (?, ?, DATE('now'), ?, ?)",
                       session["user_id"], "SELL", (lookup(symbol[0]))['price'], shares)
        except Exception:
            return redirect("/")

        return redirect("/")

    else:
        currentStocks = db.execute("SELECT symbol FROM stocks WHERE user_id = ?", session["user_id"])
        return render_template("sell.html", currentStocks=currentStocks)
