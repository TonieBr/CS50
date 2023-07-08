from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite: ")

# Executes a Query and Returns a list of Dictionaries
rows = db.execute("SELECT COUNT(*) as N FROM favorites WHERE problem = ?", favorite)

for row in rows:
    print(row["N"])