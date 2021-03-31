#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Asking what the change is
    float dollars;
    do 
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars < 0);
    
    //converting to cents
    int cents = round(dollars * 100);
    
    //counting how many coins needed
    int i = 0;
    
    while (cents > 0)
    {
        if (cents >= 25)
        {
            i = i + 1;
            cents = cents - 25;
        }
        else if (cents >= 10)
        {
            i = i + 1;
            cents = cents - 10;
        }
        else if (cents >= 5)
        {
            i = i + 1;
            cents = cents - 5;
        }
        else if (cents >= 1)
        {
            i = i + cents;
            cents = 0;
        }
    }
    // Printing result
    printf("%i\n", i);
    
    
}