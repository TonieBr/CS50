#include <stdio.h>
#include <cs50.h>

const int N = 3;
float average(int array[]);

int main(void)
{
    // Declare Array
    int scores[N];

    // Fill Array
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int ("Score: ");
    }

    printf("Average: %.2f\n", average(scores));
}

// Function Average //
float average (int array[])
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += array[i];
    }
    return (sum / (float) N);
}