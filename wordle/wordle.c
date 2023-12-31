#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
string get_guess(int wordsize);
int check_word(string guess, int wordsize, int status[], string choice);
void print_word(string guess, int wordsize, int status[]);
int score;

int main(int argc, string argv[])
{
    // ensures an input of 1 argument
    if (argc != 2)
    {
        printf("Usage: ./world wordsize\n");
        return 1;
    }

    int wordsize = 0;

    //ensure argv[1] is either 5, 6, 7, or 8 and store that value in wordsize instead
    if ((int) argv[1][0] > 56 || (int) argv[1][0] < 53)
    {
        printf("Error: wordsize must be either 5, 6, 7, or 8\n");
        return 1;
    }
    wordsize = argv[1][0] - 48;

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    string choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        string guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // set all elements of status array initially to 0, aka WRONG
        for (int j = 0; j < wordsize; j++)
        {
            status[j] = 0;
        }

        // Calculate score for the guess
        score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            break;
        }
    }

    // Print the game's result
    if (score == wordsize * 2)
    {
        printf("You won!\n");
    }
    else
    {
        printf("Failure! The word was %s\n", choice);
    }

    return 0;
}

string get_guess(int wordsize)
{
    string guess = "";

    // loop to check input length
    for (int q = 0; q < wordsize; q += 0)
        if (guess[q] != 0 && guess[wordsize] == 0)
        {
            q++;
        }
        else
        {
            guess = get_string("Input a %i-letter word: ", wordsize);
        }

    return guess;
}

int check_word(string guess, int wordsize, int status[], string choice)
{
    score = 0;
    printf("%s\n", choice);
    // compare guess to choice and score points as appropriate, storing points in status

    // main loop
    for (int k = 0; k < wordsize; k++)
    {
        if (guess[k] == choice[k])
        {
            score += 2;
            status[k] = 2;
        }
        else
        {
            // loop to check for similar letters but not in the same place
            for (int l = 0; l < wordsize; l++)
            {
                if (guess[k] == choice[l])
                {
                    score += 1;
                    status[k] = 1;
                    break;
                }
            }
        }
    }
    return score;
}

void print_word(string guess, int wordsize, int status[])
{
    // print word character-for-character with correct color coding, then reset terminal font to normal

    // For Loop if Colours
    for (int z = 0; z < wordsize; z++)
    {
        if (status[z] == 0)
        {
            printf(RED"%c", guess[z]);
        }
        if (status[z] == 1)
        {
            printf(YELLOW"%c", guess[z]);
        }
        if (status[z] == 2)
        {
            printf(GREEN"%c", guess[z]);
        }
    }
    printf(RESET"\n");
    return;
}
