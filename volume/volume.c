// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

// Array to store data from the .wav header from input
uint8_t header[HEADER_SIZE];

// Buffer to store audio samples from input .wav
int16_t buffer;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Read Input Header
    //fwrite(&buffer, sizeof(uint8_t), HEADER_SIZE, input);


    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Copy header from input file to output file
    // READ FROM INPUT
    fread(&header, sizeof(uint8_t), HEADER_SIZE, input);

    // WRITE TO OUTPUT
    fwrite(&header, sizeof(uint8_t), HEADER_SIZE, output);

    // Read samples from input file and write updated data to output file
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
