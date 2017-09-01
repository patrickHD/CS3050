BIN = hw1
CC = gcc
CFLAGS = -Wall -g

$(BIN) : frontend.c parser.o input_error.o
	$(CC) $(CFLAGS) frontend.c parser.o input_error.o -o $(BIN)

parser.o : parser.c
	$(CC) $(CFLAGS) parser.c -c

input_error.o : input_error.c
	$(CC) $(CFLAGS) input_error.c -c

clean:
	rm *.o $(BIN)
