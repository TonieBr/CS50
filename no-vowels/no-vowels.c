// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

string replace(string word);

int main(int argc, string argv[])
{

    if (argc == 1 || argc > 2)
    {
        printf("Wrong input!\n");
        return 0;
    }

    if (argc == 2)
    {
        replace(argv[1]);
        printf("%s\n", argv[1]);
    }
}

// FUNCTIONS

string replace(string word)
{
    int i = 0;
    while (word[i] != 0)
    {
        switch (word[i])
        {
            case 97:
                word[i] = 54;
                break;

            case 101:
                word[i] = 51;
                break;

            case 105:
                word[i] = 49;
                break;

            case 111:
                word[i] = 48;
                break;
        }
        i++;
    }
    return word;
}