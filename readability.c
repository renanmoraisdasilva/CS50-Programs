#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

float compute_letters(string text);
float compute_sentences(string text);
int length;
int num_words;
int num_sentences;

int main(void)
{
    num_words = 1;
    num_sentences = 0;
    
    //Get text from user
    string text = get_string("Text: ");
    length = strlen(text);
    
    //Compute number of letter per 100 words
    float ave_letters = (compute_letters(text));
    
    
    //Compute number of sentences per 100 words
    float ave_sentences = (compute_sentences(text));
    
    
    //Calculate grade
    int grade = (round)((0.0588 * ave_letters) - (0.296 * ave_sentences) - 15.8);
    
    
    //Print results
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

float compute_letters(string text)
{
    int sum_letters = 0;
    
    //Counting letters and words
    for (int i = 0; i < length; i++)
    {
        text[i] = toupper(text[i]);
        if (text[i] >= 65 && text[i] <= 90)
        {
            sum_letters += 1;
        }
        else if (text[i] == 32) 
        {
            num_words += 1;
        }
        
    }
    
    float ave = (sum_letters) / (float)(num_words) * 100;
    
    return ave;
}

float compute_sentences(string text)
{
    for (int j = 0; j < length; j++)
    {
        if (text[j] == 33 || text[j] == 46 || text[j] == 63)
        {
            num_sentences += 1;
        }
    }
   
    float ave = (num_sentences / (float)(num_words)) * 100;
    return ave;
}