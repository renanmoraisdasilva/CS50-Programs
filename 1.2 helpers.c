#include "helpers.h"
#include <stdio.h>
#include <tgmath.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int j = 0;
        int color = 0;
        for (j = 0; j < width; j++)
        {
            color = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = color;
            image[i][j].rgbtRed = color;
            image[i][j].rgbtGreen = color;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for(int i = 0; i < height; i++)
    {
        float tempb = 0;
        float tempr = 0;
        float tempg = 0;
        
        for(int j = 0; j < floor(width/2.0); j++)
        {
            tempb = image[i][j].rgbtBlue;
            tempr = image[i][j].rgbtRed;
            tempg = image[i][j].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width-j-1].rgbtBlue;
            image[i][j].rgbtRed = image[i][width-j-1].rgbtRed;
            image[i][j].rgbtGreen = image[i][width-j-1].rgbtGreen;
            image[i][width-j-1].rgbtBlue = tempb;
            image[i][width-j-1].rgbtRed = tempr;
            image[i][width-j-1].rgbtGreen = tempg;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int temp_red = 0;
    int temp_blue = 0;
    int temp_green = 0;
    float counter = 0;

    RGBTRIPLE image_2[height][width];
    
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            for (int i = h - 1; i <= h + 1; i++)
            {
                for (int j = w - 1; j <= w + 1; j++)
                {
                    if (i < 0 || j < 0 || i >= height || j >= width)
                    {
                    }
                    else
                    {
                        temp_blue += image[i][j].rgbtBlue;
                        temp_red += image[i][j].rgbtRed;
                        temp_green += image[i][j].rgbtGreen;
                        counter += 1;
                        
                    }
                }
            }
            image_2[h][w].rgbtBlue = round(temp_blue / counter);
            image_2[h][w].rgbtRed = round(temp_red / counter);
            image_2[h][w].rgbtGreen = round(temp_green / counter);
            temp_blue = 0;
            temp_red = 0;
            temp_green = 0;
            counter = 0;
        }
    }
    
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtBlue = image_2[h][w].rgbtBlue;
            image[h][w].rgbtRed = image_2[h][w].rgbtRed;
            image[h][w].rgbtGreen = image_2[h][w].rgbtGreen;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    int temp_redgx = 0;
    int temp_bluegx = 0;
    int temp_greengx = 0;
    int temp_redgy = 0;
    int temp_bluegy = 0;
    int temp_greengy = 0;
    int counter = 0;

    RGBTRIPLE image_2[height][width];
    
    int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            for (int i = h - 1; i <= h + 1; i++)
            {
                for (int j = w - 1; j <= w + 1; j++)
                {
                    if (i < 0 || j < 0 || i >= height || j >= width)
                    {
                    }
                    else
                    {
                        temp_bluegx += image[i][j].rgbtBlue * gx[i-h+1][j-w+1];
                        temp_redgx += image[i][j].rgbtRed * gx[i-h+1][j-w+1];
                        temp_greengx += image[i][j].rgbtGreen * gx[i-h+1][j-w+1];
                        
                        temp_bluegy += image[i][j].rgbtBlue * gy[i-h+1][j-w+1];
                        temp_redgy += image[i][j].rgbtRed * gy[i-h+1][j-w+1];
                        temp_greengy += image[i][j].rgbtGreen * gy[i-h+1][j-w+1];
                        
                    }
                }
            }
            image_2[h][w].rgbtBlue = fmin(round(sqrt((temp_bluegx*temp_bluegx) + (temp_bluegy*temp_bluegy))),255);
            image_2[h][w].rgbtRed = fmin(round(sqrt((temp_redgx*temp_redgx) + (temp_redgy*temp_redgy))),255);
            image_2[h][w].rgbtGreen = fmin(round(sqrt((temp_greengx*temp_greengx) + (temp_greengy*temp_greengy))),255);
            /*if(image_2[h][w].rgbtBlue > 255.0)
            {
                image_2[h][w].rgbtBlue = 255.0;
            }
            if(image_2[h][w].rgbtRed > 255.0)
            {
                image_2[h][w].rgbtRed = 255.0;
            }
            if(image_2[h][w].rgbtGreen > 255.0)
            {
                image_2[h][w].rgbtGreen = 255.0;
            }*/
            temp_bluegx = 0;
            temp_redgx = 0;
            temp_greengx = 0;
            temp_bluegy = 0;
            temp_redgy = 0;
            temp_greengy = 0;
        }
    }
    
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            image[h][w].rgbtBlue = image_2[h][w].rgbtBlue;
            image[h][w].rgbtRed = image_2[h][w].rgbtRed;
            image[h][w].rgbtGreen = image_2[h][w].rgbtGreen;
        }
    }
    
    return;
}
