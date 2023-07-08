#include <cs50.h>
#include <stdio.h>

int PyramidSize;

int main(void)
{
    do
    {
        PyramidSize = get_int("How big should the pyramid be? ");
    }
    while (PyramidSize <= 0 || PyramidSize > 8);

    // General Loop Pyramid //
    for (int i = 1; i < PyramidSize + 1; i++)
    {
        // Left Spaces //
        for (int j = PyramidSize; j > i; j--)
        {
            printf(" ");
        }

        // Left Hashes //
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }

        // Gaps //
        printf("  ");

        // Right Hashes //
        for (int l = 0; l < i; l++)
        {
            printf("#");
        }


        printf("\n");
    }
}