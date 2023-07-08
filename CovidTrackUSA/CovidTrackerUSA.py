import csv
import requests


def main():
    # Read NYTimes Covid Database
    download = requests.get(
        "https://raw.githubusercontent.com/nytimes/covid-19-data/master/us-states.csv"
    )
    decoded_content = download.content.decode("utf-8")
    file = decoded_content.splitlines()
    reader = csv.DictReader(file)

    # Construct 14 day lists of new cases for each states
    new_cases = calculate(reader)

    # Create a list to store selected states
    states = []
    print("Choose one or more states to view average COVID cases.")
    print("Press enter when done.\n")

    while True:
        state = input("State: ")
        if state in new_cases:
            states.append(state)
        if len(state) == 0:
            break

    print(f"\nSeven-Day Averages")

    # Print out 7-day averages for this week vs last week
    comparative_averages(new_cases, states)


# Create a dictionary to store 14 most recent days of new cases by state
def calculate(reader):
    # Dictionaries
    new_cases = {}
    previous_cases = {}

    for x in reader:
        if not x['state'] in new_cases:
            new_cases[x['state']] = [x['cases']]
            previous_cases[x['state']] = [x['cases']]
        else:
            DailyCases = int(x['cases']) - int(previous_cases[x['state']][-1])
            new_cases[x['state']].append(DailyCases)
            previous_cases[x['state']].append(x['cases'])
            if len(new_cases[x['state']]) > 15:
                new_cases[x['state']].pop(0)

    return new_cases


# Calculate and print out seven day average for given state
def comparative_averages(new_cases, states):
    for x in states:
        if x in new_cases:
            Average = sum(new_cases[x][8:]) / 7
            PreviousAverage = sum(new_cases[x][1:8]) / 7
            try:
                Percentage = ((Average - PreviousAverage) / PreviousAverage) * 100
            except ZeroDivisionError:
                print(f"No cases detected in {x}!")
                continue

            if Percentage > 0:
                print(f"{x} had a 7-day average of {Average:.0f} cases/day and an increase of {Percentage:.0f}%")
            else:
                Percentage = abs(Percentage)
                print(f"{x} had a 7-day average of {Average:.0f} cases/day and an decrease of {Percentage:.0f}%")


main()
