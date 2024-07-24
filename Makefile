# Makefile for Socket Communication Example

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SERVER_SRC = server.c
CLIENT_SRC = client.c
SERVER_BIN = server.exe
CLIENT_BIN = client.exe

.PHONY: all clean

all: $(SERVER_BIN) $(CLIENT_BIN)

$(SERVER_BIN): $(SERVER_SRC)
	$(CC) $(CFLAGS) -o $(SERVER_BIN) $(SERVER_SRC)

$(CLIENT_BIN): $(CLIENT_SRC)
	$(CC) $(CFLAGS) -o $(CLIENT_BIN) $(CLIENT_SRC)

clean:
	rm -f $(SERVER_BIN) $(CLIENT_BIN)
