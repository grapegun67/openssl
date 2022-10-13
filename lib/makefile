all:
        gcc -fPIC -c aes.c
        gcc -shared -o libaes.so aes.o
        rm *.o

clean:
        rm  -f *.o *.so
