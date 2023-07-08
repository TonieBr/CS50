#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

string word1, word2;
int compute_score(string word);

int main(void)
{
    // Get input words from both players
    word1 = get_string("Player 1: ");
    word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

}

// FUNCTIONS

int compute_score(string word)
{
    int i = 0;
    int sum = 0;
    while (word[i] != 0)
    {
        int x = word[i] - 0;
        // Convert all to lower string if capitals
        // Alternative Ctype islower/isupper
        if (x > 64 && x < 91)
        {
            x += 32;
        }

        // Pair to POINTS index values
        if (x > 96 && x < 123)
        {
            x -= 97;
            sum += POINTS[x];
        }
        i++;
    }
    return sum;
    i = 0;
    sum = 0;
}
