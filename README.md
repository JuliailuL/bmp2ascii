```text
     $$\                                $$$$$$\                               $$\ $$\ 
     $$ |                              $$  __$$\                              \__|\__|
     $$$$$$$\  $$$$$$\$$$$\   $$$$$$\  \__/  $$ |$$$$$$\   $$$$$$$\  $$$$$$$\ $$\ $$\ 
     $$  __$$\ $$  _$$  _$$\ $$  __$$\  $$$$$$  |\____$$\ $$  _____|$$  _____|$$ |$$ |
     $$ |  $$ |$$ / $$ / $$ |$$ /  $$ |$$  ____/ $$$$$$$ |\$$$$$$\  $$ /      $$ |$$ |
     $$ |  $$ |$$ | $$ | $$ |$$ |  $$ |$$ |     $$  __$$ | \____$$\ $$ |      $$ |$$ |
     $$$$$$$  |$$ | $$ | $$ |$$$$$$$  |$$$$$$$$\\$$$$$$$ |$$$$$$$  |\$$$$$$$\ $$ |$$ |
     \_______/ \__| \__| \__|$$  ____/ \________|\_______|\_______/  \_______|\__|\__|
                             $$ |                                                     
                             $$ |                                                     
                             \__|                                                                                                    
```

**bmp2ascii** – a small command‑line tool in C that converts 24‑bit BMP images into ASCII art, viewable directly in the terminal.

## Overview

This project reads BMP (bitmap) image files, processes their pixel data (with gamma correction and aspect‑ratio adjustments), and outputs a text-based ASCII‑art representation.  
It’s meant as a demonstration of low-level image processing, file parsing in C, memory management, and basic algorithmic transformation from bitmap to character‑raster art.

## Features & Highlights

- Converts 24-bit BMP images into ASCII art suitable for terminal display. :contentReference[oaicite:2]{index=2}  
- Supports gamma correction for perceptual brightness — improves visual resemblance between original image and ASCII output. :contentReference[oaicite:3]{index=3}  
- Maintains aspect ratio by scaling pixel-to-character mapping (each pixel → two characters wide). :contentReference[oaicite:4]{index=4}  
- Allows switching between “simple” (fast, coarse) and “dense” (detailed, slower) ASCII ramps for variable output quality. :contentReference[oaicite:5]{index=5}  
- Includes example bitmap files + automated test script to generate outputs — shows that project includes testing and reproducibility. :contentReference[oaicite:6]{index=6}

## Use Cases

- Quick “toy” transformation of small images to ASCII art — fun, retro, novelty output.  
- Learning exercise: parsing binary image formats, understanding BMP headers, working in C, implementing brightness/gamma adjustments.  
- Proof of competence in low-level programming, memory management, and transformation of data formats.

## Installation & Usage

```bash
# Clone this repo
git clone https://github.com/JuliailuL/bmp2ascii.git
cd bmp2ascii

# Build
make

# Run conversion
./conv path/to/image.bmp

# Example (convert built-in sample):
./conv examples/snail.bmp

## Project Structure
```pgsql
.
├── ascii.c / ascii.h     # ASCII conversion logic
├── bmp.c   / bmp.h       # BMP header parsing and pixel reading
├── main.c                # Program entry point
├── examples/             # Sample BMP files + test script
│   ├── snail.bmp
│   ├── tasten.bmp
│   ├── face.bmp
│   ├── wein.bmp
│   ├── ampel.bmp
│   └── run_tests.sh
├── Makefile              # Build instructions
└── README.md             # This file
```


## Testing
To run all example conversions and generate ASCII outputs automatically:
```bash
cd examples
./run_tests.sh
```


## What I Learned / Why I Built This

Parsing binary file formats (BMP), handling endianness and headers.

Working in plain C — manual memory management, pointers, arrays.

Translating pixel-based image data into character-based output — mapping luminance to ASCII ramps.

Writing a reusable CLI tool with clear build and usage instructions.

Practicing clean project structure and documentation for better readability and usability.



## License
This project is released under the MIT License — see LICENSE
 for details.
