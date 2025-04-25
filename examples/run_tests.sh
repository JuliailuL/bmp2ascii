#!/bin/bash
# examples/run_tests.sh

# Ensure the script is executable: chmod +x run_tests.sh

# Navigate to the examples directory
cd "$(dirname "$0")"

# List of BMP files to test
images=("snail.bmp" "face.bmp" "ampel.bmp" "tasten.bmp" "wein.bmp")

# Loop through each image and convert to ASCII
for img in "${images[@]}"; do
    echo "Processing $img..."
    ../conv "$img" > "${img%.bmp}_ascii.txt"
done

echo "All tests completed."