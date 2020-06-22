// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 5381;

// Hash table
node *table[N];
int words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    char lowerWord[LENGTH + 1];
    for (int i = 0; i < strlen(word); i++)
    {
        lowerWord[i] = tolower(word[i]);
    }
    lowerWord[strlen(word)] = '\0';
    int hashIndex = hash(lowerWord); // need to change to lower because the hashIndex that load function make is all lowercase
    node *cursor = table[hashIndex];
    while (cursor != NULL)
    {
        int result = strcasecmp(cursor->word, word);
        if (result == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    // TODO
    return false;
}

// Hashes word to a number
//reference from http://www.cse.yorku.ca/~oz/hash.html;
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash % N;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    char word[45];
    FILE *file = fopen(dictionary, "r");
    if (!file)
    {
        return false;
    }
    while (fscanf(file, "%s", word) != EOF)
    {
        words++;
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, word);
        int hashIndex = hash(word);
        n->next = table[hashIndex];
        table[hashIndex] = n;

    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i ++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *tmp = cursor->next;
            free(cursor);
            cursor = tmp;
        }
    }
    // TODO
    return true;
}
