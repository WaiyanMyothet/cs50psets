#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int n;
    do
    {
        n = get_int("Enter height: ");

    }
    while (n < 1 || n > 8);
    for (int i = 1; i <= n; i++)
    {
        for (int j = n - i; j > 0; j--)
        {
            printf(" ");
        }
        for (int z = 1; z <= i; z++)
        {
            printf("#");
        }
        printf("  ");
        for (int y = 1; y <= i; y++)
        {
            printf("#");
        }

        printf("\n");
    }



}