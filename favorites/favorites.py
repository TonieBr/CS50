import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    counts = {}

    #next(row) If wanting to skip first line in ordinary list
    for row in reader:
        favorite = row["problem"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

#def get_value(language):
#    return counts[language]

#for favorite in sorted(counts, key=get_value, reverse=True):
for favorite in sorted(counts, key=lambda problem: counts[problem], reverse=True):
    print(f"{favorite}: {counts[favorite]}")

favorite = input("Favorite: ").title()
if favorite in counts:
    print(f"{favorite}: {counts[favorite]}")
