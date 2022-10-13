#ifndef _AES_H_
#define _AES_H_

#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/des.h>

#define KEY_BIT 256

static const unsigned char CIPHER_KEY[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','1','2','3','4','5','6'};

int     p_encrypt(unsigned char *p_in, unsigned char *p_out, int size, char *iv);
int     p_decrypt(unsigned char *p_in, unsigned char *p_out, int size, char *iv);
void    p_print_byte(unsigned char* data, int len);

#endif
