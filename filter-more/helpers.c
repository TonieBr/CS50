#include "helpers.h"
#include "math.h"
#include "stdio.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float AveragePixel = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = AveragePixel;
            image[i][j].rgbtGreen = AveragePixel;
            image[i][j].rgbtRed = AveragePixel;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, k = 1; j < (width / 2); j++, k++)
        {
            RGBTRIPLE Temp = image[i][j];
            image[i][j] = image[i][width - k];
            image[i][width - k] = Temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Make Copy of Original Values
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    // Blur image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Upper Left
            if (i == 0 && j == 0)
            {
                // Calculate Average
                float BlurPixelBlue = round((copy[i][j].rgbtBlue +
                                             copy[i][j + 1].rgbtBlue +
                                             copy[i + 1][j].rgbtBlue +
                                             copy[i + 1][j + 1].rgbtBlue) /
                                            4.0);

                float BlurPixelRed = round((copy[i][j].rgbtRed +
                                            copy[i][j + 1].rgbtRed +
                                            copy[i + 1][j].rgbtRed +
                                            copy[i + 1][j + 1].rgbtRed) /
                                           4.0);

                float BlurPixelGreen = round((copy[i][j].rgbtGreen +
                                              copy[i][j + 1].rgbtGreen +
                                              copy[i + 1][j].rgbtGreen +
                                              copy[i + 1][j + 1].rgbtGreen) /
                                             4.0);

                // Apply on Pixel
                image[i][j].rgbtBlue = BlurPixelBlue;
                image[i][j].rgbtRed = BlurPixelRed;
                image[i][j].rgbtGreen = BlurPixelGreen;
                continue;
            }

            // Down Left
            if (i == height - 1 && j == 0)
            {
                // Calculate Average
                float BlurPixelBlue = round((copy[i - 1][j].rgbtBlue +
                                             copy[i - 1][j + 1].rgbtBlue +
                                             copy[i][j].rgbtBlue +
                                             copy[i][j + 1].rgbtBlue) /
                                            4.0);

                float BlurPixelRed = round((copy[i - 1][j].rgbtRed +
                                            copy[i - 1][j + 1].rgbtRed +
                                            copy[i][j].rgbtRed +
                                            copy[i][j + 1].rgbtRed) /
                                           4.0);

                float BlurPixelGreen = round((copy[i - 1][j].rgbtGreen +
                                              copy[i - 1][j + 1].rgbtGreen +
                                              copy[i][j].rgbtGreen +
                                              copy[i][j + 1].rgbtGreen) /
                                             4.0);

                // Apply on Pixel
                image[i][j].rgbtBlue = BlurPixelBlue;
                image[i][j].rgbtRed = BlurPixelRed;
                image[i][j].rgbtGreen = BlurPixelGreen;
                continue;
            }

            // Upper Right
            if (i == 0 && j == width - 1)
            {
                // Calculate Average
                float BlurPixelBlue = round((copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue +
                                             copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) / 4.0);
                float BlurPixelRed = round((copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed +
                                            copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) / 4.0);
                float BlurPixelGreen = round((copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen +
                                              copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 4.0);

                // Apply on Pixel
                image[i][j].rgbtBlue = BlurPixelBlue;
                image[i][j].rgbtRed = BlurPixelRed;
                image[i][j].rgbtGreen = BlurPixelGreen;
                continue;
            }

            // Down Right
            if (i == height - 1 && j == width - 1)
            {
                // Calculate Average
                float BlurPixelBlue = round((copy[i - 1][j].rgbtBlue + copy[i - 1][j - 1].rgbtBlue +
                                             copy[i][j].rgbtBlue + copy[i][j - 1].rgbtBlue) / 4.0);
                float BlurPixelRed = round((copy[i - 1][j].rgbtRed + copy[i - 1][j - 1].rgbtRed +
                                            copy[i][j].rgbtRed + copy[i][j - 1].rgbtRed) / 4.0);
                float BlurPixelGreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j - 1].rgbtGreen +
                                              copy[i][j].rgbtGreen + copy[i][j - 1].rgbtGreen) / 4.0);

                // Apply on Pixel
                image[i][j].rgbtBlue = BlurPixelBlue;
                image[i][j].rgbtRed = BlurPixelRed;
                image[i][j].rgbtGreen = BlurPixelGreen;
                continue;
            }

            if (i == 0)
            {
                // Calculate Average
                float BlurPixelBlue = round((copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                             copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0);
                float BlurPixelRed = round((copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                            copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);
                float BlurPixelGreen = round((copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen +
                                              copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0);

                // Apply on Pixel
                image[i][j].rgbtBlue = BlurPixelBlue;
                image[i][j].rgbtRed = BlurPixelRed;
                image[i][j].rgbtGreen = BlurPixelGreen;
                continue;
            }

            if (i == height - 1)
            {
                // Calculate Average
                float BlurPixelBlue = round((copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                                             copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue) / 6.0);
                float BlurPixelRed = round((copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                                            copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed) / 6.0);
                float BlurPixelGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                                              copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen) / 6.0);

                // Apply on Pixel
                image[i][j].rgbtBlue = BlurPixelBlue;
                image[i][j].rgbtRed = BlurPixelRed;
                image[i][j].rgbtGreen = BlurPixelGreen;
                continue;
            }

            if (j == 0)
            {
                // Calculate Average
                float BlurPixelBlue = round((copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue + copy[i][j].rgbtBlue +
                                             copy[i][j + 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 6.0);
                float BlurPixelRed = round((copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed + copy[i][j].rgbtRed +
                                            copy[i][j + 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 6.0);
                float BlurPixelGreen = round((copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen + copy[i][j].rgbtGreen +
                                              copy[i][j + 1].rgbtGreen + copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 6.0);

                // Apply on Pixel
                image[i][j].rgbtBlue = BlurPixelBlue;
                image[i][j].rgbtRed = BlurPixelRed;
                image[i][j].rgbtGreen = BlurPixelGreen;
                continue;
            }

            if (j == width - 1)
            {
                // Calculate Average
                float BlurPixelBlue = round((copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i][j - 1].rgbtBlue +
                                             copy[i][j].rgbtBlue + copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue) / 6.0);
                float BlurPixelRed = round((copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i][j - 1].rgbtRed +
                                            copy[i][j].rgbtRed + copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed) / 6.0);
                float BlurPixelGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i][j - 1].rgbtGreen +
                                              copy[i][j].rgbtGreen + copy[i + 1][j - 1].rgbtGreen + copy[i + 1][j].rgbtGreen) / 6.0);

                // Apply on Pixel
                image[i][j].rgbtBlue = BlurPixelBlue;
                image[i][j].rgbtRed = BlurPixelRed;
                image[i][j].rgbtGreen = BlurPixelGreen;
                continue;
            }

            // Calculate Average
            float BlurPixelBlue = round((copy[i - 1][j - 1].rgbtBlue + copy[i - 1][j].rgbtBlue + copy[i - 1][j + 1].rgbtBlue +
                                         copy[i][j - 1].rgbtBlue + copy[i][j].rgbtBlue + copy[i][j + 1].rgbtBlue +
                                         copy[i + 1][j - 1].rgbtBlue + copy[i + 1][j].rgbtBlue + copy[i + 1][j + 1].rgbtBlue) / 9.0);
            float BlurPixelRed = round((copy[i - 1][j - 1].rgbtRed + copy[i - 1][j].rgbtRed + copy[i - 1][j + 1].rgbtRed +
                                        copy[i][j - 1].rgbtRed + copy[i][j].rgbtRed + copy[i][j + 1].rgbtRed +
                                        copy[i + 1][j - 1].rgbtRed + copy[i + 1][j].rgbtRed + copy[i + 1][j + 1].rgbtRed) / 9.0);
            float BlurPixelGreen = round((copy[i - 1][j - 1].rgbtGreen + copy[i - 1][j].rgbtGreen + copy[i - 1][j + 1].rgbtGreen +
                                          copy[i][j - 1].rgbtGreen + copy[i][j].rgbtGreen + copy[i][j + 1].rgbtGreen + copy[i + 1][j - 1].rgbtGreen +
                                          copy[i + 1][j].rgbtGreen + copy[i + 1][j + 1].rgbtGreen) / 9.0);

            // Apply on Pixel
            image[i][j].rgbtBlue = BlurPixelBlue;
            image[i][j].rgbtRed = BlurPixelRed;
            image[i][j].rgbtGreen = BlurPixelGreen;
        }
    }
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // Make Copy of Original Values
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Upper Left
            if (i == 0 && j == 0)
            {
                // Red Channel
                int RedX = 2 * (copy[i][j + 1].rgbtRed) + 1 * (copy[i + 1][j + 1].rgbtRed);
                int RedY = 2 * (copy[i + 1][j].rgbtRed) + 1 * (copy[i + 1][j + 1].rgbtRed);
                // Green Channel
                int GreenX = 2 * (copy[i][j + 1].rgbtGreen) + 1 * (copy[i + 1][j + 1].rgbtGreen);
                int GreenY = 2 * (copy[i + 1][j].rgbtGreen) + 1 * (copy[i + 1][j + 1].rgbtGreen);
                // Blue Channel
                int BlueX = 2 * (copy[i][j + 1].rgbtBlue) + 1 * (copy[i + 1][j + 1].rgbtBlue);
                int BlueY = 2 * (copy[i + 1][j].rgbtBlue) + 1 * (copy[i + 1][j + 1].rgbtBlue);

                // Red Channel
                float XYRed = round(sqrt((RedX * RedX) + (RedY * RedY)));
                if (XYRed > 255)
                {
                    XYRed = 255;
                }

                // Green Channel
                float XYGreen = round(sqrt((GreenX * GreenX) + (GreenY * GreenY)));
                if (XYGreen > 255)
                {
                    XYGreen = 255;
                }

                // Blue Channel
                float XYBlue = round(sqrt((BlueX * BlueX) + (BlueY * BlueY)));

                if (XYBlue > 255)
                {
                    XYBlue = 255;
                }

                image[i][j].rgbtRed = XYRed;
                image[i][j].rgbtGreen = XYGreen;
                image[i][j].rgbtBlue = XYBlue;

                continue;
            }

            // Down Left
            if (i == height - 1 && j == 0)
            {
                // Red Channel
                int RedX = 1 * (copy[i - 1][j + 1].rgbtRed) + 2 * (copy[i][j + 1].rgbtRed);
                int RedY = -2 * (copy[i - 1][j].rgbtRed) + -1 * (copy[i - 1][j + 1].rgbtRed);
                // Green Channel
                int GreenX = 1 * (copy[i - 1][j + 1].rgbtGreen) + 2 * (copy[i][j + 1].rgbtGreen);
                int GreenY = -2 * (copy[i - 1][j].rgbtGreen) + -1 * (copy[i - 1][j + 1].rgbtGreen);
                // Blue Channel
                int BlueX = 1 * (copy[i - 1][j + 1].rgbtBlue) + 2 * (copy[i][j + 1].rgbtBlue);
                int BlueY = -2 * (copy[i - 1][j].rgbtBlue) + -1 * (copy[i - 1][j + 1].rgbtBlue);

                // Red Channel
                float XYRed = round(sqrt((RedX * RedX) + (RedY * RedY)));
                if (XYRed > 255)
                {
                    XYRed = 255;
                }

                // Green Channel
                float XYGreen = round(sqrt((GreenX * GreenX) + (GreenY * GreenY)));
                if (XYGreen > 255)
                {
                    XYGreen = 255;
                }

                // Blue Channel
                float XYBlue = round(sqrt((BlueX * BlueX) + (BlueY * BlueY)));

                if (XYBlue > 255)
                {
                    XYBlue = 255;
                }

                image[i][j].rgbtRed = XYRed;
                image[i][j].rgbtGreen = XYGreen;
                image[i][j].rgbtBlue = XYBlue;

                continue;
            }

            // Upper Right
            if (i == 0 && j == width - 1)
            {
                // Red Channel
                int RedX = -2 * (copy[i][j - 1].rgbtRed) + -1 * (copy[i + 1][j - 1].rgbtRed);
                int RedY = 1 * (copy[i + 1][j - 1].rgbtRed) + 2 * (copy[i + 1][j].rgbtRed);
                // Green Channel
                int GreenX = -2 * (copy[i][j - 1].rgbtGreen) + -1 * (copy[i + 1][j - 1].rgbtGreen);
                int GreenY = 1 * (copy[i + 1][j - 1].rgbtGreen) + 2 * (copy[i + 1][j].rgbtGreen);
                // Blue Channel
                int BlueX = -2 * (copy[i][j - 1].rgbtBlue) + -1 * (copy[i + 1][j - 1].rgbtBlue);
                int BlueY = 1 * (copy[i + 1][j - 1].rgbtBlue) + 2 * (copy[i + 1][j].rgbtBlue);

                // Red Channel
                float XYRed = round(sqrt((RedX * RedX) + (RedY * RedY)));
                if (XYRed > 255)
                {
                    XYRed = 255;
                }

                // Green Channel
                float XYGreen = round(sqrt((GreenX * GreenX) + (GreenY * GreenY)));
                if (XYGreen > 255)
                {
                    XYGreen = 255;
                }

                // Blue Channel
                float XYBlue = round(sqrt((BlueX * BlueX) + (BlueY * BlueY)));

                if (XYBlue > 255)
                {
                    XYBlue = 255;
                }

                image[i][j].rgbtRed = XYRed;
                image[i][j].rgbtGreen = XYGreen;
                image[i][j].rgbtBlue = XYBlue;

                continue;
            }

            // Down Right
            if (i == height - 1 && j == width - 1)
            {
                // Red Channel
                int RedX = -1 * (copy[i - 1][j - 1].rgbtRed) + -2 * (copy[i][j - 1].rgbtRed);
                int RedY = -1 * (copy[i - 1][j - 1].rgbtRed) + -2 * (copy[i - 1][j].rgbtRed);
                // Green Channel
                int GreenX = -1 * (copy[i - 1][j - 1].rgbtGreen) + -2 * (copy[i][j - 1].rgbtGreen);
                int GreenY = -1 * (copy[i - 1][j - 1].rgbtGreen) + -2 * (copy[i - 1][j].rgbtGreen);
                // Blue Channel
                int BlueX = -1 * (copy[i - 1][j - 1].rgbtBlue) + -2 * (copy[i][j - 1].rgbtBlue);
                int BlueY = -1 * (copy[i - 1][j - 1].rgbtBlue) + -2 * (copy[i - 1][j].rgbtBlue);

                // Red Channel
                float XYRed = round(sqrt((RedX * RedX) + (RedY * RedY)));
                if (XYRed > 255)
                {
                    XYRed = 255;
                }

                // Green Channel
                float XYGreen = round(sqrt((GreenX * GreenX) + (GreenY * GreenY)));
                if (XYGreen > 255)
                {
                    XYGreen = 255;
                }

                // Blue Channel
                float XYBlue = round(sqrt((BlueX * BlueX) + (BlueY * BlueY)));

                if (XYBlue > 255)
                {
                    XYBlue = 255;
                }

                image[i][j].rgbtRed = XYRed;
                image[i][j].rgbtGreen = XYGreen;
                image[i][j].rgbtBlue = XYBlue;

                continue;
            }

            if (i == 0)
            {
                // Red Channel
                int RedX = -2 * (copy[i][j - 1].rgbtRed) + 2 * (copy[i][j + 1].rgbtRed) + -1 *
                           (copy[i + 1][j - 1].rgbtRed) + 1 * (copy[i + 1][j + 1].rgbtRed);
                int RedY = 1 * (copy[i + 1][j - 1].rgbtRed) + 2 * (copy[i + 1][j].rgbtRed) + 1 * (copy[i + 1][j + 1].rgbtRed);
                // Green Channel
                int GreenX = -2 * (copy[i][j - 1].rgbtGreen) + 2 * (copy[i][j + 1].rgbtGreen) + -1 *
                             (copy[i + 1][j - 1].rgbtGreen) + 1 * (copy[i + 1][j + 1].rgbtGreen);
                int GreenY = 1 * (copy[i + 1][j - 1].rgbtGreen) + 2 * (copy[i + 1][j].rgbtGreen) + 1 * (copy[i + 1][j + 1].rgbtGreen);
                // Blue Channel
                int BlueX = -2 * (copy[i][j - 1].rgbtBlue) + 2 * (copy[i][j + 1].rgbtBlue) + -1 *
                            (copy[i + 1][j - 1].rgbtBlue) + 1 * (copy[i + 1][j + 1].rgbtBlue);
                int BlueY = 1 * (copy[i + 1][j - 1].rgbtBlue) + 2 * (copy[i + 1][j].rgbtBlue) + 1 * (copy[i + 1][j + 1].rgbtBlue);

                // Red Channel
                float XYRed = round(sqrt((RedX * RedX) + (RedY * RedY)));
                if (XYRed > 255)
                {
                    XYRed = 255;
                }

                // Green Channel
                float XYGreen = round(sqrt((GreenX * GreenX) + (GreenY * GreenY)));
                if (XYGreen > 255)
                {
                    XYGreen = 255;
                }

                // Blue Channel
                float XYBlue = round(sqrt((BlueX * BlueX) + (BlueY * BlueY)));

                if (XYBlue > 255)
                {
                    XYBlue = 255;
                }

                image[i][j].rgbtRed = XYRed;
                image[i][j].rgbtGreen = XYGreen;
                image[i][j].rgbtBlue = XYBlue;

                continue;
            }

            if (i == height - 1)
            {
                // Red Channel
                int RedX = -1 * (copy[i - 1][j - 1].rgbtRed) + 1 * (copy[i - 1][j + 1].rgbtRed) + -2 *
                           (copy[i][j - 1].rgbtRed) + 2 * (copy[i][j + 1].rgbtRed);
                int RedY = -1 * (copy[i - 1][j - 1].rgbtRed) + -2 * (copy[i - 1][j].rgbtRed) + -1 * (copy[i - 1][j + 1].rgbtRed);
                // Green Channel
                int GreenX = -1 * (copy[i - 1][j - 1].rgbtGreen) + 1 * (copy[i - 1][j + 1].rgbtGreen) + -2 *
                             (copy[i][j - 1].rgbtGreen) + 2 * (copy[i][j + 1].rgbtGreen);
                int GreenY = -1 * (copy[i - 1][j - 1].rgbtGreen) + -2 * (copy[i - 1][j].rgbtGreen) + -1 * (copy[i - 1][j + 1].rgbtGreen);
                // Blue Channel
                int BlueX = -1 * (copy[i - 1][j - 1].rgbtBlue) + 1 * (copy[i - 1][j + 1].rgbtBlue) + -2 *
                            (copy[i][j - 1].rgbtBlue) + 2 * (copy[i][j + 1].rgbtBlue);
                int BlueY = -1 * (copy[i - 1][j - 1].rgbtBlue) + -2 * (copy[i - 1][j].rgbtBlue) + -1 * (copy[i - 1][j + 1].rgbtBlue);

                // Red Channel
                float XYRed = round(sqrt((RedX * RedX) + (RedY * RedY)));
                if (XYRed > 255)
                {
                    XYRed = 255;
                }

                // Green Channel
                float XYGreen = round(sqrt((GreenX * GreenX) + (GreenY * GreenY)));
                if (XYGreen > 255)
                {
                    XYGreen = 255;
                }

                // Blue Channel
                float XYBlue = round(sqrt((BlueX * BlueX) + (BlueY * BlueY)));

                if (XYBlue > 255)
                {
                    XYBlue = 255;
                }

                image[i][j].rgbtRed = XYRed;
                image[i][j].rgbtGreen = XYGreen;
                image[i][j].rgbtBlue = XYBlue;

                continue;
            }

            if (j == 0)
            {
                // Red Channel
                int RedX = 1 * (copy[i - 1][j + 1].rgbtRed) + 2 * (copy[i][j + 1].rgbtRed) + 1 * (copy[i + 1][j + 1].rgbtRed);
                int RedY = -2 * (copy[i - 1][j].rgbtRed) + -1 * (copy[i - 1][j + 1].rgbtRed) + 2 *
                           (copy[i + 1][j].rgbtRed) + 1 * (copy[i + 1][j + 1].rgbtRed);
                // Green Channel
                int GreenX = 1 * (copy[i - 1][j + 1].rgbtGreen) + 2 * (copy[i][j + 1].rgbtGreen) + 1 * (copy[i + 1][j + 1].rgbtGreen);
                int GreenY = -2 * (copy[i - 1][j].rgbtGreen) + -1 * (copy[i - 1][j + 1].rgbtGreen) + 2 *
                             (copy[i + 1][j].rgbtGreen) + 1 * (copy[i + 1][j + 1].rgbtGreen);
                // Blue Channel
                int BlueX = 1 * (copy[i - 1][j + 1].rgbtBlue) + 2 * (copy[i][j + 1].rgbtBlue) + 1 * (copy[i + 1][j + 1].rgbtBlue);
                int BlueY = -2 * (copy[i - 1][j].rgbtBlue) + -1 * (copy[i - 1][j + 1].rgbtBlue) + 2 *
                            (copy[i + 1][j].rgbtBlue) + 1 * (copy[i + 1][j + 1].rgbtBlue);

                // Red Channel
                float XYRed = round(sqrt((RedX * RedX) + (RedY * RedY)));
                if (XYRed > 255)
                {
                    XYRed = 255;
                }

                // Green Channel
                float XYGreen = round(sqrt((GreenX * GreenX) + (GreenY * GreenY)));
                if (XYGreen > 255)
                {
                    XYGreen = 255;
                }

                // Blue Channel
                float XYBlue = round(sqrt((BlueX * BlueX) + (BlueY * BlueY)));

                if (XYBlue > 255)
                {
                    XYBlue = 255;
                }

                image[i][j].rgbtRed = XYRed;
                image[i][j].rgbtGreen = XYGreen;
                image[i][j].rgbtBlue = XYBlue;

                continue;
            }

            if (j == width - 1)
            {
                // Red Channel
                int RedX = -1 * (copy[i - 1][j - 1].rgbtRed) + -2 * (copy[i][j - 1].rgbtRed) + -1 * (copy[i + 1][j - 1].rgbtRed);
                int RedY = -1 * (copy[i - 1][j - 1].rgbtRed) + -2 * (copy[i - 1][j].rgbtRed) + 1 *
                           (copy[i + 1][j - 1].rgbtRed) + 2 * (copy[i + 1][j].rgbtRed);
                // Green Channel
                int GreenX = -1 * (copy[i - 1][j - 1].rgbtGreen) + -2 * (copy[i][j - 1].rgbtGreen) + -1 * (copy[i + 1][j - 1].rgbtGreen);
                int GreenY = -1 * (copy[i - 1][j - 1].rgbtGreen) + -2 * (copy[i - 1][j].rgbtGreen) + 1 *
                             (copy[i + 1][j - 1].rgbtGreen) + 2 * (copy[i + 1][j].rgbtGreen);
                // Blue Channel
                int BlueX = -1 * (copy[i - 1][j - 1].rgbtBlue) + -2 * (copy[i][j - 1].rgbtBlue) + -1 * (copy[i + 1][j - 1].rgbtBlue);
                int BlueY = -1 * (copy[i - 1][j - 1].rgbtBlue) + -2 * (copy[i - 1][j].rgbtBlue) + 1 *
                            (copy[i + 1][j - 1].rgbtBlue) + 2 * (copy[i + 1][j].rgbtBlue);

                // Red Channel
                float XYRed = round(sqrt((RedX * RedX) + (RedY * RedY)));
                if (XYRed > 255)
                {
                    XYRed = 255;
                }

                // Green Channel
                float XYGreen = round(sqrt((GreenX * GreenX) + (GreenY * GreenY)));
                if (XYGreen > 255)
                {
                    XYGreen = 255;
                }

                // Blue Channel
                float XYBlue = round(sqrt((BlueX * BlueX) + (BlueY * BlueY)));

                if (XYBlue > 255)
                {
                    XYBlue = 255;
                }

                image[i][j].rgbtRed = XYRed;
                image[i][j].rgbtGreen = XYGreen;
                image[i][j].rgbtBlue = XYBlue;

                continue;
            }

            // Red Channel
            int RedX = -1 * (copy[i - 1][j - 1].rgbtRed) + 1 * (copy[i - 1][j + 1].rgbtRed) + -2 * (copy[i][j - 1].rgbtRed) + 2 *
                       (copy[i][j + 1].rgbtRed) + -1 * (copy[i + 1][j - 1].rgbtRed) + 1 * (copy[i + 1][j + 1].rgbtRed);
            int RedY = -1 * (copy[i - 1][j - 1].rgbtRed) + -2 * (copy[i - 1][j].rgbtRed) + -1 * (copy[i - 1][j + 1].rgbtRed) + 1 *
                       (copy[i + 1][j - 1].rgbtRed) + 2 * (copy[i + 1][j].rgbtRed) + 1 * (copy[i + 1][j + 1].rgbtRed);
            // Green Channel
            int GreenX = -1 * (copy[i - 1][j - 1].rgbtGreen) + 1 * (copy[i - 1][j + 1].rgbtGreen) + -2 * (copy[i][j - 1].rgbtGreen) + 2 *
                         (copy[i][j + 1].rgbtGreen) + -1 * (copy[i + 1][j - 1].rgbtGreen) + 1 * (copy[i + 1][j + 1].rgbtGreen);
            int GreenY = -1 * (copy[i - 1][j - 1].rgbtGreen) + -2 * (copy[i - 1][j].rgbtGreen) + -1 * (copy[i - 1][j + 1].rgbtGreen) + 1 *
                         (copy[i + 1][j - 1].rgbtGreen) + 2 * (copy[i + 1][j].rgbtGreen) + 1 * (copy[i + 1][j + 1].rgbtGreen);
            // Blue Channel
            int BlueX = -1 * (copy[i - 1][j - 1].rgbtBlue) + 1 * (copy[i - 1][j + 1].rgbtBlue) + -2 * (copy[i][j - 1].rgbtBlue) + 2 *
                        (copy[i][j + 1].rgbtBlue) + -1 * (copy[i + 1][j - 1].rgbtBlue) + 1 * (copy[i + 1][j + 1].rgbtBlue);
            int BlueY = -1 * (copy[i - 1][j - 1].rgbtBlue) + -2 * (copy[i - 1][j].rgbtBlue) + -1 * (copy[i - 1][j + 1].rgbtBlue) + 1 *
                        (copy[i + 1][j - 1].rgbtBlue) + 2 * (copy[i + 1][j].rgbtBlue) + 1 * (copy[i + 1][j + 1].rgbtBlue);

            // Red Channel
            float XYRed = round(sqrt((RedX * RedX) + (RedY * RedY)));
            if (XYRed > 255)
            {
                XYRed = 255;
            }

            // Green Channel
            float XYGreen = round(sqrt((GreenX * GreenX) + (GreenY * GreenY)));
            if (XYGreen > 255)
            {
                XYGreen = 255;
            }

            // Blue Channel
            float XYBlue = round(sqrt((BlueX * BlueX) + (BlueY * BlueY)));

            if (XYBlue > 255)
            {
                XYBlue = 255;
            }

            image[i][j].rgbtRed = XYRed;
            image[i][j].rgbtGreen = XYGreen;
            image[i][j].rgbtBlue = XYBlue;
        }
    }
}
