x = 1
y = 2

print(f"x is {x}, y is {y}")
x, y = y, x
print(f"x is {x},x, y is {y}")

# Unlike C, where the address had to be directly accessed (&) due to passing by reference