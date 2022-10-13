LPATH=$(shell echo ~)/openssl/lib

all:
        gcc main.c -c -laes.h
        gcc main.o -L$(LPATH) -laes -lssl -lcrypto -o main
        rm *.o
        
clean:
        rm -f *.o main
