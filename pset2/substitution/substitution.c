#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>

int toupper(int c);
int tolower(int c);
int toascii(int c);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key \n");
        return 1;
    }
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution key \n");
            return 1;
        }
        else if (n != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (toupper(argv[1][i]) == toupper(argv[1][j]))
            {
                printf("Key must contain character for once.\n");
                return 1;
            }
        }
    }
    string s = get_string("plaintext: ");
    printf("ciphertext: ");
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        if (!isalpha(s[i]))
        {
            printf("%c", s[i]);
        }
        else if (isupper(s[i]))
        {
            int value = toascii(s[i]) - 65;
            printf("%c", toupper(argv[1][value]));
        }
        else
        {
            int value = toascii(s[i]) - 97;
            printf("%c", tolower(argv[1][value]));
        }
    }
    printf("\n");
}