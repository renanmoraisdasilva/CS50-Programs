#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int v;
    int n;
    int j;
    
    // Ask height between 1 and 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    
    //Print Stairs
    for (v = 0; v < height; v++)
    {
        for (n = height - 1 - v; n > 0; n--)
        {
            printf(" ");
        }
        for (j = height - 1 - v; j < height; j++)    
        {
            printf("#");
        }
        printf("\n");
    }
        
}
