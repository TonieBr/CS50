#include <cs50.h>
#include <stdio.h>

float StartSize;
float EndSize;

int main(void)
{
    // TODO: Prompt for start size
    do
    {
        StartSize = get_int("How many llama's do we start with?\n");
    }
    while (StartSize < 9);

    // TODO: Prompt for end size
    do
    {
        EndSize = get_int("How many llama's do we end with?\n");
    }
    while (EndSize < StartSize);


    // TODO: Calculate number of years until we reach threshold
    int HowManyYears = 0;
    int Size = StartSize;
    while (Size < EndSize)
    {
        Size = Size - (Size / 4) + (Size / 3);
        HowManyYears++;
    }




    // TODO: Print number of years

    printf("Years: %i\n", HowManyYears);
}
