#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Create 2D Array to represent all pixels (height x width)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // hexadecimal colouring!
            if (image[i][j].rgbtBlue == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtRed == 0x00)
            {
                image[i][j].rgbtBlue = 0xff;
            }
        }
    }
}
