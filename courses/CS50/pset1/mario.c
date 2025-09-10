#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // height has to be between 1 and 8
    int space;
    int height;
    int gap = 2;
    do
    {
        height = get_int("Height:");
    } 
    while (height < 1 || height > 8);

    // print
    for (int i = 1; i <= height; i++)
    {
        // init: space
        if (i == height)
        {
            space = 0; 
        } 
        else
        {
            space = height - i;
        }
        // print: space
        for (int j = 1; j <= space; j++)
        {
            printf(" ");
        }
        // print: hash
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // print: gap
        printf("  ");
        // print: hash
        for (int k = 0; k < i; k++)
        {
            printf("#");
        }
        // print: new line
        printf("\n");
    }
}



