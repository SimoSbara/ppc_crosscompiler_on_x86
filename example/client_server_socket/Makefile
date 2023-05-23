# This is a comment line
CC_X86=g++
CC_PPC=powerpc-7450-linux-gnu-g++
# CFLAGS will be the options passed to the compiler.
CFLAGS= -c -Wall
all:
	$(CC_X86) client.cpp -o client_x86
	$(CC_X86) server.cpp -o server_x86	
	$(CC_PPC) client.cpp -o client_ppc
	$(CC_PPC) server.cpp -o server_ppc
clean:
	rm -rf *.o 