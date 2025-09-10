#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int main(int argc, string argv[])
{   
    string key;
    int status = 1;
    if (argc == 2)
    {
        int key_len;
        key = argv[1];
        for (key_len = 0; key[key_len] != '\0'; ++key_len);
        if (key_len == 26)
        {
            int counter = 0; // count number of non-special characters 
            for (int i = 0; i < 26; i++)
            {
                if isalpha(key[i])
                {
                    ++counter;
                }
            }
            if (counter == 26) // normal characters
            {
                int c = 0; // count frequency of characters in a string
                int char_count[26] = {0};
                while (key[c] != '\0')
                {
                    if (isupper(key[c])) // uppercase
                    {
                        char_count[key[c] - 65]++;
                    }
                    else
                    {
                        char_count[key[c] - 97]++;
                    }
                    c++;
                }

                int second_counter = 0;
                for (c = 0; c < 26; c++)
                {
                    if (char_count[c] != 1)
                    {
                        ++second_counter;
                    }
                }
                if (second_counter == 0)
                {
                    status = 0; 
                }
                else
                {
                    status = 1;
                }
            }
            else
            {
                status = 1;
            }
        }
        else
        {
            printf("Key must contain 26 characters\n");
            status = 1;
        }
    }
    else 
    {
        printf("Usage: %s key\n", argv[0]);
        status = 1;
    }

    if (status == 0) // conditions = true
    {
        string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // lower case and upper case alphabet
        char lowercase[26];
        for (int i = 0; i < 26; i++)
        {
            lowercase[i] = uppercase[i] + 32;
        }

        string x = get_string("plaintext: "); // return
        printf("ciphertext: ");

        int x_len;
        for (x_len = 0; x[x_len] != '\0'; ++x_len);

        for (int j = 0; j < x_len; j++)
        {
            if (isalpha(x[j]))
            {
                if (islower(x[j])) // lowercase
                {
                    int k;
                    for (k = 0; k < 26; ++k)
                    {
                        if (x[j] == lowercase[k])
                        {
                            if islower(key[k])
                            {
                                printf("%c", key[k]);
                            }
                            else
                            {
                                printf("%c", key[k] + 32);
                            }
                            break;
                        }
                    }
                }
                else if (isupper(x[j])) // uppercase
                {
                    int k;
                    for (k = 0; k < 26; ++k)
                    {
                        if (x[j] == uppercase[k])
                        {
                            if islower(key[k])
                            {
                                printf("%c", key[k] - 32);
                            }
                            else
                            {
                                printf("%c", key[k]);
                            }
                            break;
                        }
                    }

                }
            } 
            else // comma, whitespace
            {
                printf("%c", x[j]);
            }
        }
        printf("\n");
        return 0;
    } 
    else if (status == 1) // condition is false 
    {
        return 1;
    }
}



