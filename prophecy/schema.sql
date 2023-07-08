CREATE TABLE students (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    student_name TEXT
);

CREATE TABLE houses (
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    house TEXT
);

CREATE TABLE assignments (
    student_id INTEGER,
    house_id INTEGER,
    FOREIGN KEY(student_id) REFERENCES students(id),
    FOREIGN KEY(house_id) REFERENCES houses(id)
);
