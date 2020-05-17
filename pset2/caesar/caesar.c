#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int toascii(int c);
int main(int argc, string argv[])
{

    // printf("%s\n",argv[1]);
    if (argc != 2)
    {
        printf("Usage: ./caesar key \n");
        return 1;
    }
    for (int j = 0, n = strlen(argv[1]); j < n ; j++)
    {
        if (!isdigit(argv[1][j]))
        {
            printf("Usage: ./caesar key \n");
            return 1;
        }
    }
    int key = atoi(argv[1]);
    //printf("key : %i\n", key);
    string s = get_string("plaingtext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isalpha(s[i]))
        {
            printf("%c", s[i]);
        }
        else
        {
            if (isupper(s[i]))
            {
                int upper = toascii(s[i]);
                int value = (((upper - 65) + key) % 26) + 65;
                printf("%c", value);
            }
            else
            {

                int lower = toascii(s[i]);
                int value = (((lower - 97) + key) % 26) + 97;
                printf("%c", value);
            }

        }

    }
    printf("\n");


}