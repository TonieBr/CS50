s = input("s: ")

t = s.capitalize()

print(f"s: {s}")
print(f"t: {t}")

# Unlike C:
# Changing a Pointer results in both being changed, Python makes auto copy
# Can compare Strings, don't directly point to different places in memoy

#s = input("s: ")
#t = input("t: ")
#
#if s == t:
#    print("Same")
#else:
#    print("Different")