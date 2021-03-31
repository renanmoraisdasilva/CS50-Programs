#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int secsum;
    int v;
    int i;
    int sum = 0;
    long j = 0;
    // Asking for number
    long credit = get_long("Number: ");
    
    if (credit < 4 * pow(10, 12) || credit > 6 * pow(10, 15))
    {
        printf("INVALID\n");
    }
    else
    {
        // Making the first sum
        for (i = 1; i < 9; i++)
        {   
            j = credit / pow(10, 2 * i - 1);
        
            j = j % 10;
            
            printf("j: %ld \n", j);
        
            int localsum = 2 * j;
            if (localsum > 10)
            {
                localsum = localsum % 10;
                sum = sum + localsum + 1;
                printf("sum: %i \n", sum);
            }
            else if (localsum == 10)
            {
                sum = sum + 1;
                printf("sum: %i \n", sum);
            }
            else
            {
                sum = sum + 2 * j;
                printf("sum:%i \n", sum);
            }
        }
        
        // Making the second sum
        for (v = 0; v < 9 ; v++)
        {
            long k = credit / pow(10, 2 * v);
            printf("k:%ld \n ", k);
            k = k % 10;
            printf("k:%ld \n", k);
            secsum = secsum + k;
            printf("secsum:%i \n", secsum);
        }
        
        // Making total sum = sum
        sum = sum + secsum;
        printf("totalsum:%i \n", sum);
        
        // Checksum
        int check = sum % 10;
        
        // Final condition
        if (check == 0)
        {
            printf("VALID \n");
            
            //Checking which card it is
            int amex = credit / pow(10, 13);
            int visa1 = credit / pow(10, 12);
            int visa2 = credit / pow(10, 15);
            int master = credit / pow(10, 14);
            
            if (amex == 34 || amex == 37)
            {
                printf("AMEX\n");
            }
            else if (visa1 == 4 || visa2 == 4)
            { 
                printf("VISA\n");
            }
            else if (master >= 51 && master <= 55)
            {
                printf("MASTERCARD");
            }
            else
            {
                printf("INVALID");
            }
        }
        else
        {
            printf("INVALID \n");
        }
    }
}