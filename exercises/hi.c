#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // char c1 = 'H';
    // char c2 = 'I';
    // char c3 = '!';

    string words[2];

    words[0] = "HI!";
    words[1] = "BYE!";

    //string s = "HI!";
    //string t = "BYE!";

    // Print alsof het een string is
    // printf("%c%c%c\n", c1, c2, c3);

    // Print de ASCI waardes //
    // printf("%i %i %i\n", c1, c2, c3);

    // Print String als array onderdelen
    // printf("%c\n%c\n%c\n", s[0], s[1], s[2]);

    // Print String als ASCI Waardes //
    // printf("%i, %i, %i, %i\n", s[0], s[1], s[2], s[3]);

    // Twee Strings worden apart gelezen door 0/nul

    printf("%s\n", words[0]);
    printf("%s\n", words[1]);

    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
    printf("%c%c%c%c\n", words[1][0], words [1][1], words[1][2], words [1][3]);
}