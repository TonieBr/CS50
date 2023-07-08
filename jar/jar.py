def main():
    jar = Jar()
    print(jar.CapacitySize)
    print()
    print(jar.__str__())
    print()

    jar.deposit(11)
    print(str(jar))
    print()

    jar.withdraw(10)
    print(str(jar))
    print()

class Jar:
    def __init__(self, capacity=12):
        if (capacity < 0):
            raise ValueError
        else:
            self.CapacitySize = capacity
            self.amount = 1

    def __str__(self):
        return self.amount * "🍪"

    def deposit(self, n):
        if (self.amount + n > self.CapacitySize):
            raise ValueError
        else:
            self.amount += n

    def withdraw(self, n):
        if (n > self.amount):
            raise ValueError
        else:
            self.amount -= n

    @property
    def capacity(self):
        return self.capacity

    @property
    def size(self):
        return self.amount

main()