#include "../inc/aes.h"

int     p_encrypt(unsigned char *plain, unsigned char *cipher, int size, char *iv)
{
        AES_KEY aes_key;
        unsigned char iv_aes[AES_BLOCK_SIZE];

        memcpy(iv_aes, iv, AES_BLOCK_SIZE);

        AES_set_encrypt_key(CIPHER_KEY, KEY_BIT, &aes_key);
        AES_cbc_encrypt(plain, cipher, size, &aes_key, iv_aes, AES_ENCRYPT);

        return (0);
}

int     p_decrypt(unsigned char *cipher, unsigned char *decrypt, int size, char *iv)
{
        AES_KEY aes_key;
        unsigned char iv_aes[AES_BLOCK_SIZE];

        memcpy(iv_aes, iv, AES_BLOCK_SIZE);

        memcpy(iv_aes, &cipher[0], AES_BLOCK_SIZE);
        memmove(&cipher[0], &cipher[AES_BLOCK_SIZE], size);

        AES_set_decrypt_key(CIPHER_KEY, KEY_BIT, &aes_key);
        AES_cbc_encrypt(cipher, decrypt, size, &aes_key, iv_aes, AES_DECRYPT);

        return (0);
}

void    p_print_byte(unsigned char* data, int len)
{
        /* 16번 마다 끊어서 출력        */
        int     ndx, idx = 16;

        printf(" [%d]\n", len);
        for (ndx = 0; ndx < len; ndx++)
        {
                printf("0x%02x ", data[ndx]);
                if (ndx == idx - 1)
                {
                        printf(" -[%d]\n", idx / 16);
                        idx += 16;
                }
        }
        printf("\n");

        return;
}
