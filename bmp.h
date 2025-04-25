#ifndef BMP_H
#define BMP_H

#include <stdbool.h>
#include <stdio.h>

// Ensure there is no padding between the struct members
#pragma pack(push, 1)
typedef struct
{
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGBTRIPLE;
#pragma pack(pop)

/**
 * Checks if the file header is a valid BMP.
 */
bool is_bmp(const unsigned char *header);

/**
 * Reads the 54-byte BMP header from file.
 */
int read_header(FILE *file, unsigned char *header);

/**
 * Converts 4 little-endian bytes to an int.
 */
int read_int_lil_endian(unsigned char *bytes);

/**
 * Extracts width and height from the BMP header.
 */
void read_bmp_dimension(unsigned char *header, int *width, int *height);

/**
 * Reads pixel data from the BMP file.
 */
RGBTRIPLE **read_pixels(FILE *file, int width, int height);

/**
 * Frees memory used by the pixel array.
 */
void free_pixels(RGBTRIPLE **pixels, int height);

#endif // BMP_H