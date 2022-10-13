#AES256 with openssl

#라이브러리 빌드:
gcc -fPIC -c aes.c;
gcc -shared -o libaes.so aes.o

#소스 빌드:
gcc main.c -c -laes.h;
gcc main.o -L~/ssl/lib -lssl -lcrypto -laes -o main
