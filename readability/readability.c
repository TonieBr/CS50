#include <cs50.h>
#include <stdio.h>

float GiveGrade(string example);

float ColemanLiau;

int main(void)
{
    string phrase = get_string("Text: ");
    GiveGrade(phrase);

    // Print Grade
    if (ColemanLiau >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (ColemanLiau < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.0f\n", ColemanLiau);
    }
}

float GiveGrade(string example)
{
    float LetterCount = 0;
    float WordCount = 1;
    float SentenceCount = 0;

    int i = 0;
    while (example[i] != 0)
    {
        // Count Letters
        if ((example[i] > 64 && example[i] < 91) || (example[i] > 96 && example[i] < 123))
        {
            LetterCount += 1;
        }

        // Count Words
        if (example[i] == 32)
        {
            WordCount += 1;
        }

        // Count Sentences
        if (example[i] == 46 || example[i] == 33 || example[i] == 63)
        {
            SentenceCount += 1;
        }
        i++;
    }

    float AverageLetters = (LetterCount / WordCount) * 100;
    float AverageSentences = (SentenceCount / WordCount) * 100;
    ColemanLiau = 0.0588 * AverageLetters - 0.296 * AverageSentences - 15.8;

    //printf("Letters: %.0f\n", LetterCount);
    //printf("Words: %.0f\n", WordCount);
    //printf("Sentences: %.0f\n", SentenceCount);
    //printf("Average Letters: %.2f\n", AverageLetters);
    //printf("Average Sentences: %.2f\n", AverageSentences);

    return ColemanLiau;
}



