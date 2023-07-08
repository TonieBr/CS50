#include <cs50.h>
#include <stdio.h>

// Input met Command Line Arguments
// string argv = woord
// int argc = aantal argvs

// Twee formats, deze of void
int main(int argc, string argv[])
{
    // één user-input --> voornaam
    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello, world\n");
    }
}