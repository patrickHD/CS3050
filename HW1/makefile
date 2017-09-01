BIN = hw1
CC = gcc
CFLAGS = -Wall -g

$(BIN) : frontend.c input_error.o
	$(CC) $(CFLAGS) frontend.c input_error.o -o $(BIN)

input_error.o : input_error.c
	$(CC) $(CFLAGS) input_error.c -c

clean:
	rm *.o $(BIN)
