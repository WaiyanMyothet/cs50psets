#include<cs50.h>
#include<stdio.h>
#include<math.h>

int main(void)
{
    float dollar;
    int coins = 0;
    do
    {
        dollar = get_float("Change Owed :");
    }
    while (dollar < 0);
    int cents = round(dollar * 100);

    while (cents >= 25)
    {
        cents -= 25;
        coins += 1;
    }
    while (cents >= 10)
    {
        cents -= 10;
        coins += 1;
    }
    while (cents >= 5)
    {
        cents -= 5;
        coins += 1;
    }
    while (cents >= 1)
    {
        cents -= 1;
        coins += 1;
    }
    printf("%i\n", coins);



}
