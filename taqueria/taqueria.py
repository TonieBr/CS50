import string
import sys

dict = {
    "Baja Taco": 4.00,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

Total = 0
while True:
    try:
        x = string.capwords(input("Item: ").lower())
        if x in dict:
            Total += dict[x]
            print(f"Total: ${Total:.2f}")
            continue

    except EOFError:
        sys.exit(0)


