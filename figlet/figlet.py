import pyfiglet
import sys
import random

# Get and Save List of Fonts
FontList = pyfiglet.FigletFont.getFonts()

# Randomize Default Font
Font = random.choice(FontList)

if len(sys.argv) == 1:
    f = pyfiglet.Figlet(font=Font)
    x = (input("Text: "))
    print (f.renderText(x))

elif len(sys.argv) == 3 and sys.argv[1] in ("-f", "--font"):
        try:
            Font = sys.argv[2]
            f = pyfiglet.Figlet(font=Font)
            x = (input("Text: "))
            print (f.renderText(x))
        except pyfiglet.FontNotFound:
            print("Please define an existing font!")
            sys.exit(1)

else:
    print("Correct Use: python figlet.py [-f or --font] [font]")
    sys.exit(1)

