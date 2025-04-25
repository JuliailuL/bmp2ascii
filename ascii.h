#ifndef ASCII_H
#define ASCII_H

#include "bmp.h" // for RGBTRIPLE

/**
 * Converts BMP pixel data into ASCII art and prints it to the terminal.
 *
 * @param pixels 2D array of RGB pixel data
 * @param width Width of the image
 * @param height Height of the image
 * @param gamma Contrast/gamma adjustment for brightness perception (e.g., 1.0 = linear, <1 = lighter, >1 = darker)
 */
void print_ascii_art(RGBTRIPLE **pixels, int width, int height, double gamma);

#endif // ASCII_H