while True:
    try:
        x = int(input("What's the Size of Pyramid: "))
        if 1 <= x <= 8:
            break
    except ValueError:
        print("Please fill in an integer between 1 and 8!")

for i in range(1, x+1, 1):
    print(" " * (x - i), end="")
    print("#" * i, end="")
    print("  ", end="")
    print("#" * i, end="")
    print("")