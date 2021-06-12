#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <cs50.h>
 
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw/n");
        return 1;
    }
    
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("File could not be opened/n");
        return 1;
    }
    
    //obtain file size
    fseek (input, 0, SEEK_END);
    int size = ftell (input);
    rewind (input);
    
    //allocate memory for buffer
    unsigned char* buffer = malloc (sizeof(char)*size);
    if (buffer == NULL)
    {
        printf("Memory error\n");
    }
    
    //reading buffer
    fread (buffer, 512, size/512, input);
    int contador = 0;
    int *locais = malloc (sizeof(int)*(size/512));
    for(int i = 0; i < size/512; i++)
    {
        if (buffer[512*i] == 0xff && buffer[512*i+1] == 0xd8 && buffer[512*i+2] == 0xff && (buffer[512*i+3] & 0xf0) == 0xe0)
        {
            locais[contador] = i;
            contador += 1;
        }
    }
    locais[contador] = size/512;
    char number[7] = {0};
    
    //writing to output files
    for(int i = 0; i < contador; i++)
    {
        sprintf(number, "%03i.jpg", i);
        FILE *output = fopen(number, "w");
        fseek (input, locais[i]*512, SEEK_SET);
        fread (buffer, 512, locais[i+1]-locais[i], input);
        fwrite(buffer, 512, locais[i+1]-locais[i], output);
        fclose(output);
    }
    fclose(input);
    free(locais);
    free(buffer);
}