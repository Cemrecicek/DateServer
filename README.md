# Socket Communication Example


This project demonstrates a basic client-server application using socket programming in C. The server sends the current date to the client upon connection.


## Overview


- **Server**: Listens on port 8080 and sends the current date to any connected client.

- **Client**: Connects to the server, receives the current date, and displays it.


## Compilation

To compile the server and client programs with `Makefile`, run the following commands:

```bash
make 
```

This will generate server.exe and client.exe files.

## Usage

### **Start the Server:**


Open a terminal and run the server.exe program:

```bash
./server.exe
```

The server will start listening on port 8080.


### **Run the Client**

Open another terminal and run the client.exe:

```bash
./client.exe
```

The client will connect to the server, receive the current date, and print it to the terminal.


## Clean Up


To remove the compiled binaries, run:

```
make clean
```

This will delete `server.exe` and `client.exe` from the project directory.
