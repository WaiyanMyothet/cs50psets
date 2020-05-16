#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int count_letters(string s);
int count_words(string s);
int count_sent(string s);
float average(int count, int wordcount);
int main(void)
{
    string s = get_string("Text :");
    int letters = count_letters(s);
    int words = count_words(s);
    int sent = count_sent(s);
    //printf("%i\n",letters);
    //printf("%i\n",words);
    // printf("%i\n",sent);
    float letteraverage = average(letters, words);
    float sentaverage = average(sent, words);
    int result = round(0.0588 * letteraverage - 0.296 * sentaverage - 15.8);
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", result);
    }
    // printf ("%i\n", result);
}

int count_letters(string s)
{
    int count = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {

        if (isdigit(s[i]) || isspace(s[i]) || ispunct(s[i]))
        {
            continue;
        }
        count += 1;
    }
    return count;
}

int count_words(string s)
{
    int count = 0;
    for (int i = 0, n = strlen(s); i < n ; i ++)
    {

        if (i == 0)
        {

            if (!isspace(s[i]))
            {

                count ++;
            }
        }

        else

        {

            if (isspace(s[i - 1]))

            {

                count ++;
            }
        }

    }
    return count;
}

int count_sent(string s)
{
    int count = 0;
    for (int i = 0, n = strlen(s); i < n ; i++)
    {
        if (s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            count ++;
        }
    }
    return count;
}

float average(int count, int wordcount)
{
    float division = (float) count / (float) wordcount;
    float result = division * 100;
    // printf("%f\n",result);
    return result;
}

