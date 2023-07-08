#include <cs50.h>
#include <stdio.h>

// Encrypts input with passed encryption key

int main(int argc, string argv[])
{
    // check if just one argument has been passed (the encryption key)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
        void abort();
    }

    // check if a correct 26-letter key has been passed, else quit
    int same = 0;
    int array[25];
    for (int i = 0; i < 26; i++)
    {
        array[i] = argv[1][i];
        //printf("%i ", array[i]);
        if (argv[1][i] < 91 && argv[1][i] > 64)
        {
        }
        // Convert everything to uppercase letters
        else if (argv[1][i] < 123 && argv[1][i] > 96)
        {
            argv[1][i] -= 32;
        }
        else
        {
            printf("Error! Please enter 26 alphabetical characters!\n");
            return 1;
            void abort();
        }
        array[i] = argv[1][i];
        // check if 26 unique characters have been passed, else quit
        for (int j = 0; j < 26; j++)
        {
            if (argv[1][j] == argv[1][i])
            {
                same++;
                // Checks if there are more than 26 equalities (= doubles) and quit
                if (same == 27)
                {
                    printf("Error! Please enter 26 unique alphabetical characters!\n");
                    return 1;
                    void abort();
                }
            }
        }

    }
    string plaintext = get_string("plaintext:  ");

    int k = 0;
    printf("ciphertext: ");
    // While-loop to convert input to encrypted letters
    while (plaintext[k] != 0)
    {
        // if upper case, take from encryption key as is
        if (plaintext[k] < 91 && plaintext[k] > 64)
        {
            plaintext[k] -= 65;
            int x = (int) plaintext[k];
            plaintext[k] = array[x];
            printf("%c", plaintext[k]);
        }
        // if lower case, convert encryption letters to lower case
        else if (plaintext[k] < 123 && plaintext[k] > 96)
        {
            plaintext[k] -= 97;
            int x = (int) plaintext[k];
            plaintext[k] = (array[x] + 32);
            printf("%c", plaintext[k]);
        }
        // if non-alphabetic, print as is
        else
        {
            printf("%c", plaintext[k]);
        }
        k++;
    }

    printf("\n");
    return 0;
}