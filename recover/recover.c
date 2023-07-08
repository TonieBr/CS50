#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;
BYTE buffer[512];


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Correct Use: ./recover [FILE] \n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    int counter = 0;
    char *filename = malloc(8 * sizeof(char));

    while (fread(buffer, 1, 512, file) == 512)
    {
        if (buffer[0] == 255 && buffer[1] == 216 && buffer[2] == 255)
        {
            // Determine File Name
            sprintf(filename, "%03i.jpg", counter);
            counter++;
        }

        if (counter > 0)
        {
            // Open Current File
            FILE *img = fopen(filename, "a");

            // Write to File
            fwrite(buffer, 1, 512, img);

            // Close File
            fclose(img);
        }
    }

    // Close Files
    fclose(file);

    // Free Allocated Memory
    free(filename);

}