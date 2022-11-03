
CC = g++
CFLAGS = -g -Wall -std=c++11
BIN = aes

all: $(BIN)

aes: aes.cpp main.cpp
	$(CC) $(CFLAGS) -o AES main.cpp aes.cpp

clean:
	@rm -f AES
