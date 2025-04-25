# bmp2ascii 
A small C program that converts BMP images into ASCII art displayed in the terminal.
 
## Features
- Converts 24-bit BMP files to ASCII art
- Uses gamma correction for perceptual brightness adjustment
- Aspect ratio aware (each pixel is printed as two characters wide) 
- Supports simple and dense ASCII ramps (easily switchable)
- Includes automated test examples with sample BMP files
 
## Usage
```
make
./conv path/to/image.bmp
```
 
### Example:
```
./conv examples/snail.bmp
```
 
## ASCII Ramps
You can experiment with different ramps by editing the ART constant in ascii.c:
```
const char *ART = "@%#*+=-:. ";  // Less detailed
// const char *ART = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/*tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$"; // Detailed
```
 
## Folder Structure
. <br>
├── ascii.c / ascii.h         # ASCII conversion logic
├── bmp.c / bmp.h             # BMP header and pixel reading <br> 
├── main.c                    # Program entry point <br>
├── examples/ <br>
│   ├── snail.bmp <br>
│   ├── tasten.bmp <br>
│   ├── face.bmp <br>
│   ├── wein.bmp <br>
│   ├── ampel.bmp <br>
│   └── run_tests.sh <br>
├── Makefile <br>
└── README.md <br>
 
## Tests
Run all example images and capture the output to text files:
```
cd examples
./run_tests.sh
```
 
## Image Sources
snail.bmp: https://people.math.sc.edu/Burkardt/data/bmp/snail.bmp <br>
tasten.bmp: https://www.pexels.com/de-de/foto/tastatur-wort-tasten-herunterladen-2882550/ <br>
face.bmp: https://www.pexels.com/de-de/foto/sonja-29940493/ <br>
wein.bmp: https://www.pexels.com/de-de/foto/hochwinkelaufnahme-verschiedener-spirituosen-in-weinglasern-7270404/ <br>
ampel.bmp: https://www.pexels.com/de-de/foto/selektive-fokusfotografie-der-ampel-1616781/ <br>
 
## Credits
This project was made possible with support from ChatGPT. The original folder layout and testing automation ideas were inspired by suggestions from the assistant. 💡🧠
