CREATE TABLE stocks (
    user_id INTEGER,
    symbol TEXT,
    amount INTEGER,
    FOREIGN KEY(user_id) REFERENCES users(id)
);

CREATE TABLE history (
    user_id INTEGER,
    trant TEXT,
    trand DATE,
    FOREIGN KEY(user_id) REFERENCES users(id)

);

SELECT * FROM users
JOIN stocks on id = stocks.user_id
JOIN history on id = history.user_id;

