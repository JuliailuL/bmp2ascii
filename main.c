#include <stdlib.h>
#include <stdio.h>
#include "ascii.h"
#include "bmp.h"

int main(int argc, char *argv[])
{
    // Accept one command line argument
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./conv FILE\n");
        return 1;
    }

    // Open the file in binary mode and check if it exists
    FILE *file = fopen(argv[1], "rb");
    if (!file)
    {
        perror("Error opening file");
        return 2;
    }

    // Read BMP header
    unsigned char header[54];
    if (!read_header(file, header))
    {
        fclose(file);
        return 3;
    }

    // Validate BMP signature
    if (!is_bmp(header))
    {
        fprintf(stderr, "Error: Not a valid BMP file.\n");
        fclose(file);
        return 4;
    }

    // Extract image dimensions
    int width, height;
    read_bmp_dimension(header, &width, &height);
    printf("Image dimensions - Width: %d, Height: %d\n", width, height);

    // Read pixel data
    RGBTRIPLE **pixels = read_pixels(file, width, height);
    if (!pixels)
    {
        fclose(file);
        return 5;
    }

    // Gamma value for brightness/contrast adjustment
    double gamma = 0.95;
    print_ascii_art(pixels, width, height, gamma);

    // Clean up
    free_pixels(pixels, height);
    fclose(file);

    return 0;
}
