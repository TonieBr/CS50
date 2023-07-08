// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Pointer to holder for dictionary words
char *memory = NULL;

// Counter for words in dictionary
int WordCount = 0;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Choose number of buckets in hash table
// Alphabetic - 26 Letters
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int hashvalue = hash(word);
    node *tmp = table[hashvalue];

    while (tmp != NULL)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    memory = malloc(LENGTH * sizeof(char));

    FILE *DICT = fopen(dictionary, "r");
    if (DICT == NULL)
    {
        return false;
    }

    node *root;
    while (fscanf(DICT, "%s", memory) != EOF)
    {
        // Determine where to put
        unsigned int index = hash(memory);
        //printf("%i \n", index);

        node *tmp = table[index];
        table[index] = malloc(sizeof(node));
        table[index]->next = table[index];
        strcpy(table[index]->word, memory);
        table[index]->next = tmp;
        WordCount++;
    }
    printf("Word Count: %i \n", WordCount);
    free(memory);
    fclose(DICT);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //printf("%i", WordCount);
    return WordCount;
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }
    }
    return true;
}
