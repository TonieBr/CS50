import sys

names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

name = input("Name: ")

if name in names:
    print("Found")
    sys.exit(0)

#for n in names:
#    if name == n:
#        print("Found")
#        sys.exit(0)

print("Not found!")
sys.exit(1)