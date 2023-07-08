import csv
import sys


def main():

    # Check for command-line usage
    if len(sys.argv) != 3:
        print("Error: Use [csvfile] [DNA text]")

    # Read database file into a variable
    DictDB = {}
    DictDB2 = {}

    file = open(sys.argv[1])
    reader = csv.DictReader(file)
    i = 0
    for x in reader:
        DictDB2.update(x)
        DictDB[i] = x
        i += 1

    # Read DNA sequence file into a variable
    file = open(sys.argv[2])
    reader = csv.reader(file)
    for x in reader:
        Sequence = x[0]

    # Find longest match of each STR in DNA sequence
    Keys = [key for key in DictDB2]
    Keys.pop(0)
    Count = {}

    for i in Keys:
        longest = longest_match(Sequence, i)
        Count[i] = f'{longest}'

    # Check database for matching profiles
    file = open(sys.argv[1])
    reader = csv.DictReader(file)
    for x in reader:
        temp = x.pop('name')
        if x == Count:
            print(temp)
            sys.exit(1)

    print("No match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
