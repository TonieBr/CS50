CreditCard = input("Number: ")

# Checks wheter digit is even
# Keeps track of total sum
even = 0
counter = 0

for i in reversed(CreditCard):
    if even == 1:
        i = str(int(i) * 2)
        if int(i) >= 10:
            counter += int(i[0]) + int(i[1])
        else:
            counter += int(i)
        even = 0
    else:
        counter += int(i)
        even += 1

# VISA Check
if (len(CreditCard) == 13 or len(CreditCard) == 16) and not counter % 10 and CreditCard[0] == '4':
    print("VISA")

# MASTERCARD Check
elif len(CreditCard) == 16 and not counter % 10 and CreditCard[0:2] in ['51', '52', '53', '54', '55']:
    print("MASTERCARD")

# AMEX Check
elif len(CreditCard) == 15 and not counter % 10 and CreditCard[0:2] in ['34', '37']:
    print("AMEX")

else:
    print("INVALID")