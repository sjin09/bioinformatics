#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{   
    // init
    string i = get_string("Text: ");
    char j[strlen(i)];
    strcpy(j, i);
    for (int x = 0; x < strlen(j); x++)
    {
        // printf("%c\t%d\n", j[x], x);

        // if strcmp(j[x], "!")
        char y = j[x];
        if (y == '!')
        {
            j[x] = '.';
        }
        else if (y == '?')
        {
            j[x] = '.';
        }
    }
    // main
    int number_of_words = 0;
    int number_of_letters = 0;
    int number_of_sentences = 0;
    // main: strcpy
    char k[strlen(i)];
    strcpy(k, j);
    // main: number of sentences
    string x = strtok(k, ".");
    while(x != NULL)
    {
        printf("%s\n", x);
        number_of_sentences++;
        x = strtok(NULL, ".");
    }
    // main: init string
    strcpy(k, j);
    string y = strtok(k, " ");
    while(y != NULL)
    {
        number_of_words++;
        for (int m = 0; m < strlen(y); m++)
        {
            char n = y[m];
            if (isalpha(n) != 0)
            {
                number_of_letters++;
            }
        }
        y = strtok(NULL, " ");
    }
    // Coleman-Liau index
    float L = (number_of_letters / (float)number_of_words) * 100;
    float S = (number_of_sentences / (float)number_of_words) * 100;
    int index = round((0.0588 * L) - (0.296 * S) - 15.8);
    printf("%d\t%d\t%d\t%f\t%f\t%d\n", number_of_letters, number_of_words, number_of_sentences, L, S ,index);
    // return
    char o[20];
    if (index < 1)
    {
        sprintf(o, "Before Grade 1");
    }
    else if (index < 16)
    {
        sprintf(o, "Grade %d", index);
    }
    else if (index > 16)
    {
        sprintf(o, "Grade 16+");
    }
    printf("%s\n", o);
}

/* 
in C single quotes are char literals, and double quotes are string literals. 
*/

