from cs50 import SQL
import csv

db = SQL("sqlite:///Final.db")

with open ("students.csv") as file:
    reader = csv.DictReader(file)

    for row in reader:

        #Houses Table
        db.execute("INSERT INTO houses (house) SELECT ? WHERE NOT EXISTS (SELECT * FROM houses WHERE house=?)", row['house'], row['house'])

        #Students Table
        db.execute ("INSERT INTO students (student_name) VALUES (?)", row['student_name'])

    	#Linked Table
        db.execute( "INSERT INTO assignments (student_id, house_id) VALUES((SELECT id FROM students WHERE student_name = ?), (SELECT id FROM houses WHERE house = ?))", row['student_name'], row['house'] )
