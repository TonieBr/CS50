#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int y = 3;
    int x = (y == 1) ? 5 : 6;
    printf("The integer is %i\n", x);
}