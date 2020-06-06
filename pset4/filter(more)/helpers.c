#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;

        }
    }
}
// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            int tempRed = image[i][j].rgbtRed;
            int tempGreen = image[i][j].rgbtGreen;
            int tempBlue = image[i][j].rgbtBlue;
            image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;
            image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;
            image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;
            image[i][width - (j + 1)].rgbtRed = tempRed;
            image[i][width - (j + 1)].rgbtGreen = tempGreen;
            image[i][width - (j + 1)].rgbtBlue = tempBlue;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumRed = 0;
            int sumGreen = 0;
            int sumBlue = 0;
            float pixel = 0.0;
            for (int x = -1; x < 2; x++)
            {
                if (i + x < 0 || i + x > height - 1)
                {
                    continue;
                }

                for (int y = -1; y < 2; y++)
                {

                    if (j + y < 0 || j + y > width - 1)
                    {

                        continue;
                    }
                    sumRed += image[i + x][j + y].rgbtRed;
                    sumGreen += image[i + x][j + y].rgbtGreen;
                    sumBlue += image[i + x][j + y].rgbtBlue;
                    pixel++;
                }
            }
            temp[i][j].rgbtBlue = round(sumBlue / pixel);
            temp[i][j].rgbtGreen = round(sumGreen / pixel);
            temp[i][j].rgbtRed = round(sumRed / pixel);
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i ++)
    {
        for (int j = 0; j < width; j++)
        {
            int GxRed = 0;
            int GxGreen = 0;
            int GxBlue = 0;
            int GyRed = 0;
            int GyGreen = 0;
            int GyBlue = 0;
            for (int x = -1; x < 2; x++)
            {
                if (i + x < 0 || i + x > height - 1)
                {
                    continue;
                }

                for (int y = -1; y < 2; y++)
                {

                    if (j + y < 0 || j + y > width - 1)
                    {
                        continue;
                    }
                    int divy = y == 1 ? -1 : y;
                    int divx = x == 1 ? -1 : x;
                    GxRed += ((divx + 2) * y) * image[i + x][j + y].rgbtRed;
                    GxGreen += ((divx + 2) * y) * image[i + x][j + y].rgbtGreen;
                    GxBlue += ((divx + 2) * y) * image[i + x][j + y].rgbtBlue;
                    GyRed += ((divy + 2) * x) * image[i + x][j + y].rgbtRed;
                    GyGreen += ((divy + 2) * x) * image[i + x][j + y].rgbtGreen;
                    GyBlue += ((divy + 2) * x) * image[i + x][j + y].rgbtBlue;

                }
            }
            int red = round(sqrt(GxRed * GxRed + GyRed * GyRed));
            int green = round(sqrt(GxGreen * GxGreen + GyGreen * GyGreen));
            int blue = round(sqrt(GxBlue * GxBlue + GyBlue * GyBlue));
            temp[i][j].rgbtRed = red > 255 ? 255 : red;
            temp[i][j].rgbtGreen = green > 255 ? 255 : green;
            temp[i][j].rgbtBlue = blue > 255 ? 255 : blue;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
}
