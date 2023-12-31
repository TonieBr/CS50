#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);
int counter = 0, loop = 1;

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    int length = strlen(input) - 1;

    if (length != -1)
    {
        counter += (input[length] - 48) * loop;
        loop *= 10;
        input[length] = 0;
        return convert(input);
    }
    else
    {
        return counter;
    }
}