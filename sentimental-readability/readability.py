# User Input
phrase = input("Text: ")

# Initialize Counters
LetterCount = 0
WordCount = 0
SentenceCount = 0

# Normalize Text
phrase = phrase.replace(",", "").replace("!", ".").replace("?", ".")

# Count
LetterCount = sum(c.isalpha() for c in phrase)
SentenceCount = len(phrase.split(".")) - 1
WordCount = len(phrase.split())

# Formula
AverageLetters = (LetterCount / WordCount) * 100
AverageSentences = (SentenceCount / WordCount) * 100
ColemanLiau = 0.0588 * AverageLetters - 0.296 * AverageSentences - 15.8

# Printers
if ColemanLiau >= 16:
    print("Grade 16+")
elif ColemanLiau < 1:
    print("Before Grade 1")
else:
    print(f"Grade {ColemanLiau:.0f}")