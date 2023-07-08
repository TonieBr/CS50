pizzas = {
    "cheese": 9,
    "pepperoni": 10,
    "vegetable": 11,
    "buffalo chicken": 12
}

n = input("What Pizza :")

for pie in pizzas:
    if pie == n:
        print("Found")
        break

for pie, price in pizzas.items():
    if pie == n:
        print(f"The price is {price}".format(price))