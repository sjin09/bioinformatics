#include <cs50.h>
#include <stdio.h>

int main(void)
{

    // init
    int sum;
    int length = 0;
    string card_type;

    // card number
    long n;
    long number_long = get_long("Number:");

    // length of integer
    n = number_long;
    while (n != 0)
    { 
        n /= 10;
        ++length; 
    }

    // int to int array
    int i = 0;
    int tmp[length];
    n = number_long;
    while (n != 0)
    { 
        tmp[i] = n % 10;
        n /= 10;
        ++i; 
    }
    // reverse int array
    int j = 0; 
    int number_array[length];
    for (i = length - 1; i > -1; i--)
    {
        number_array[j] =  tmp[i];
        ++j;
    }

    // determine card type
    if (length == 15 && number_array[0] == 3 && number_array[1] == 4)
    {
        card_type = "AMEX";
    }
    else if (length == 15 && number_array[0] == 3 && number_array[1] == 7)
    {
        card_type = "AMEX";
    }
    else if (length == 16 && number_array[0] == 5 && number_array[1] == 1)
    {
        card_type = "MASTERCARD";
    }
    else if (length == 16 && number_array[0] == 5 && number_array[1] == 2)
    {
        card_type = "MASTERCARD";
    }
    else if (length == 16 && number_array[0] == 5 && number_array[1] == 3)
    {
        card_type = "MASTERCARD";
    }
    else if (length == 16 && number_array[0] == 5 && number_array[1] == 4)
    {
        card_type = "MASTERCARD";
    }
    else if (length == 16 && number_array[0] == 5 && number_array[1] == 5)
    {
        card_type = "MASTERCARD";
    }
    else if (length == 16 && number_array[0] == 4)
    {
        card_type = "VISA";
    }
    else if (length == 13 && number_array[0] == 4)
    {
        card_type = "VISA";
    }
    else
    {
        card_type = "INVALID";
    }

    // init: x, y, z
    int x = 0; 
    int y = 0;

    // iterate from second-to-last digit and decrement by two
    for (int k = length - 2; k > -1; k -= 2)
    {
        y = number_array[k] * 2; // multiply by two
        if (y == 0)
        {
            x += 0;
        }
        else
        {

            int y_tmp = y;
            int y_index = 0;
            int y_length = 0;
            while (y_tmp != 0) // length of number
            { 
                y_tmp /= 10;
                ++y_length; 
            }
            y_tmp = y;
            while (y_tmp != 0)
            { 
                x += y_tmp % 10;
                y_tmp /= 10;
                ++y_index; 
            }
        }
    }
    // iterate from last-digit and decrement by two
    for (int k = length - 1; k > -1; k -= 2)
    {
        x += number_array[k];
    }
    // x length;
    int x_tmp = x;
    int x_length = 0;
    while (x_tmp != 0) // length of number
    { 
        x_tmp /= 10;
        ++x_length; 
    }
    // x array
    x_tmp = x;
    int x_index = 0; 
    int x_array[x_length];
    while (x_tmp != 0)
    { 
        x_array[x_index] = x_tmp % 10;
        x_tmp /= 10;
        ++x_index; 
    }
    // if last digit of x == 0
    if (x_array[0] == 0)
    {
        printf("%s\n", card_type);
    }
    else
    {
        printf("%s\n", "INVALID");
    }
}



