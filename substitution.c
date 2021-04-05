#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(int argc, string argv[])
{
    //Check if key is valid
    if (argc == 1 || argc > 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int length_key = strlen(argv[1]);
    if (length_key != 26)
    {
        printf("Only 26 non-equal letters");
        return 1;
    }
    int checksum = 0;
    for (int i = 0; i < length_key; i++)
    {
        if (isalpha(argv[1][i]) == 0)
        {
            printf("Only letters\n");
            return 1;
        }
        checksum += toupper(argv[1][i]);
    }
    if (checksum != 2015)
    {
        printf("key should not repeat any letters");
        return 1;
    }
    
    //Asking for plaintext
    string text = get_string("plaintext: ");
    int length_text = strlen(text);

    //Make the ciphertext
    for (int j = 0; j < length_text; j++)
    {
        if (islower(text[j]) > 0)
        {
            int letter = text[j] - 97;
            text[j] = argv[1][letter];
            //making it lowercase in case key changed it
            text[j] = tolower(text[j]);
        }
        else if (isupper(text[j]) > 0)
        {
            int letter = text[j] - 65;
            text[j] = argv[1][letter];
            //making it uppercase in case key changed it
            text[j] = toupper(text[j]);
        }
    }
    
    //Print results
    printf("ciphertext: %s\n", text);
    return 0;
}