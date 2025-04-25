#include <stdlib.h> // malloc, free
#include "bmp.h"

// Check if file header corresponds to BMP format
bool is_bmp(const unsigned char *header)
{
    return header[0] == 'B' && header[1] == 'M';
}

// Read 54-byte BMP header
int read_header(FILE *file, unsigned char *header)
{
    size_t readBytes = fread(header, sizeof(unsigned char), 54, file);
    if (readBytes != 54)
    {
        perror("Error reading BMP header");
        return 0;
    }
    return 1;
}

// Convert 4 bytes from little endian to int 
int read_int_lil_endian(unsigned char *bytes)
{
    return  (int)(bytes[0]) |
           ((int)(bytes[1]) << 8) |
           ((int)(bytes[2]) << 16) |
           ((int)(bytes[3]) << 24);
}

// Extract width and height from BMP header
void read_bmp_dimension(unsigned char *header, int *width, int *height)
{
    *width = read_int_lil_endian(&header[18]);
    *height = read_int_lil_endian(&header[22]);
}

// Read pixel data from BMP file
RGBTRIPLE **read_pixels(FILE *file, int width, int height)
{
    // BMP format padding: each row must be multiple of 4 bytes
    int rowSize = (width * sizeof(RGBTRIPLE) + 3) & ~3;

    // Allocate memory for row pointers
    RGBTRIPLE **pixels = malloc(height * sizeof(RGBTRIPLE *));
    if (!pixels)
    {
        perror("Failed to allocate memory for row pointers");
        return NULL;
    }

    // Move file pointer to the start of the pixel data
    fseek(file, 54, SEEK_SET);

    for (int i = 0; i < height; i++)
    {
        int row = height - 1 - i; // BMP stores pixels bottom-to-top

        // Allocate memory to hold a row of pixels
        pixels[row] = malloc(width * sizeof(RGBTRIPLE));
        if (!pixels[row])
        {
            perror("Failed to allocate memory for pixel rows");

            // Free the previously allocated rows
            for (int j = 0; j < row; j++)
            {
                free(pixels[j]);
            }
            free(pixels);
            return NULL;
        }

        // Read the pixel data of the row
        fread(pixels[row], sizeof(RGBTRIPLE), width, file);

        // Skip padding bytes
        int padding = rowSize - width * sizeof(RGBTRIPLE);
        fseek(file, padding, SEEK_CUR);
    }

    return pixels;
}

// Free memory used for pixel data
void free_pixels(RGBTRIPLE **pixels, int height)
{
    for (int i = 0; i < height; i++)
    {
        free(pixels[i]);
    }
    free(pixels);
}