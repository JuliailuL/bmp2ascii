#include "ascii.h"
#include <math.h>
#include <stdio.h>
#include <string.h>


// Less detailed tone representation
// const char *ART = " .:-=+*#%@";

// Less detailed tone representation inversed
const char *ART = "@%#*+=-:. ";

// Dense ASCII ramp for representing detailed tone 
// const char *ART = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/*tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";

// Inverted ASCII ramp
// const char *ART = "$@B%8&WM#*oahkbdpqwmZO0QCLJUYXzcvunxrjft*/\\|)(1}{][?-_+~><i!lI;:,\"^`'. ";


/**
 * Converts BMP pixel data into ASCII art and prints it to the terminal.
 *
 * @param pixels 2D array of RGB pixel data
 * @param width Width of the image
 * @param height Height of the image
 * @param gamma Contrast/gamma adjustment for brightness perception (e.g., 1.0 = linear, <1 = lighter, >1 = darker)
 */
void print_ascii_art(RGBTRIPLE **pixels, int width, int height, double gamma)
{
    const int lenArt = strlen(ART) -1;
    for (int i = 0; i < height; i++) //row
    {
        for (int j = 0; j < width; j++) //column
        {
            RGBTRIPLE pixel = pixels[i][j];
            
            // Luminance formula with square root emphasis for perceptual brightness           
            double gray = sqrt(0.299 * pixel.red * pixel.red + 
                               0.587 * pixel.green * pixel.green + 
                               0.114 * pixel.blue * pixel.blue); 

            // Optional contrast shaping
            gray = pow(gray, gamma);
            if (gray > 255) gray = 255;
            
            // Map grayscale to ASCII ramp
            int index = (int) round((gray / 255.0) * lenArt);
            if (index < 0) index = 0;
            if (index > lenArt) index = lenArt;
            
            // Print two characters to approximate aspect ratio
            printf("%c", ART[index]);
            printf("%c", ART[index]);
        }
        printf("\n");
    }
}