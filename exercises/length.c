#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string name = get_string("What's your name? ");

    int n = 0;
    // While loop want geen specifiek hoeveel loops
    while (name[n] != '\0')
    {
        n++;
    }
    printf("%i\n", n);

    // Alternative - string.h
    int x = strlen(name);
    printf("%i\n", x);
}