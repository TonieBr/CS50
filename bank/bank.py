x = input("Greeting: ")
x = x.lower()
x = x.strip()

if x.startswith("hello"):
    print("$0")
elif x.startswith("h"):
    print("$20")
else:
    print("$100")
