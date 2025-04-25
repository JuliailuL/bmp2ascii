CC = gcc 	#Set the compiler
CFLAGS = -Wall -Wextra -std=c11		#Compiler flags for warnings and standards
OBJ = main.o bmp.o ascii.o 		#Object files to link
TARGET = conv	#Name of the final executable

# -lm is for linking with math.h

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) -lm 

main.o: main.c bmp.h ascii.h
	$(CC) $(CFLAGS) -c main.c

bmp.o: bmp.c bmp.h
	$(CC) $(CFLAGS) -c bmp.c

ascii.o: ascii.c ascii.h bmp.h
	$(CC) $(CFLAGS) -c ascii.c

clean:
	rm -f $(OBJ) $(TARGET) 