#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    //Checking if argument is valid
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
    
    //Calculating length of key string
    int length = strlen(argv[1]);
    
    //Putting key string into an int
    int key = 0;
    int sum_key = 0;
    for (int i = 0; i < length ; i++)
    {
        if (isdigit(argv[1][i]) == 0)
        {
            printf("Usage: ./caesar key");
            return 1;
        }
        else
        {
            key = (argv[1][i] - 48) * pow(10, length - 1 - i);
            sum_key = sum_key + key;
        }
    }
    
    //Calculating remainder so number is between 0 and 26  
    sum_key = sum_key % 26;
    
    //Asking for plaintext and calculating length of string
    string text = get_string("plaintext:  ");
    int length_text = strlen(text);
    
    //Making the cyphertext
    for (int j = 0; j < length_text ; j++)
    {
        if (islower(text[j]) > 0)
        {
            text[j] = text[j] - 96;
            text[j] = (text[j] + sum_key) % 26;
            text[j] = text[j] + 96;
        }
        else if (isupper(text[j]) > 0)
        {
            text[j] = (((text[j] - 64) + sum_key) % 26) + 64;
            
        }
    }
    
    //Printing ciphertext
    printf("ciphertext: %s\n", text);
    return 0;
}
