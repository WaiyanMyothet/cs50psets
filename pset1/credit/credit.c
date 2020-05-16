#include<cs50.h>
#include<stdio.h>

int main(void)
{
    long cardNumber;
    long n;
    long number;
    int length = 0;
    do
    {
        cardNumber = get_long("Number :");
    }
    while (cardNumber < 0);
    n = cardNumber;
    number = cardNumber;
    while (n != 0)
    {
        n /= 10;
        length++;
    }

    if (length < 13 || length > 16)
    {
        printf("INVALID\n");
    }
    else
    {
        int odd = 0;
        int even = 0;
        int result = 0;
        int digit = 0;
        string card;
        int first = 0;
        int second = 0;
        for (int i = 1; i <= length; i++)
        {
            digit = number % 10;
            number /= 10;
            //printf("digit : %i\n",digit);
            if (i == length - 1)
            {
                second = digit;
            }
            if (i == length)
            {
                first = digit;
            }
            if (i % 2 == 0)
            {
                int multiply = digit * 2;
                if (multiply / 10 != 0)
                {
                    int twoDigit = multiply;
                    do
                    {
                        int oneDigit = twoDigit % 10;
                        twoDigit /= 10;
                        even = even + oneDigit;
                        //   printf("even :%i\n",even);
                    }
                    while (twoDigit != 0);
                }
                else
                {
                    even = even + multiply;
                    // printf("even : %i\n",even);
                }

            }
            else
            {
                odd = odd + digit;
                //printf ("odd : %i\n",odd);
            }
        }
        result = odd + even;
        //printf("%i\n",result);
        if (result % 10 != 0)
        {
            printf("INVALID\n");
        }
        else
        {
            int topTwo = first * 10 + second;
            if (first == 4)
            {
                printf("VISA\n");
            }
            else if (topTwo == 34 || topTwo == 37)
            {
                printf("AMEX\n");
            }
            else if (topTwo > 50 && topTwo < 56)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }

}