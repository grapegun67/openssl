/********************************************************************************************************************************/
/* {참고]                                                                                                                       */
/* 1. iv값은 AES함수에 들어간 다음에 변형되므로 암호화, 복호화마다 지역변수로 각각 선언                                               */
/* 2. AES암호화 비트수(128, 256)마다 지역 변수들의 크기를 수정 필요                                                                 */
/********************************************************************************************************************************/
#include "../inc/aes.h"

int     main(int argc, char *args[])
{
        int     len;
        int     encrypt_size;
        char    editb[2048];
        char    lastb[2048];

        unsigned char   o_sour[2048];
        unsigned char   o_temp[2048];
        unsigned char   o_encrypt[2048];
        unsigned char   o_decrypt[2048];
        unsigned char   iv_aes1[AES_BLOCK_SIZE]          = {0x3d,0xaf,0xba,0x42,0x9d,0x9e,0xb4,0x30,0xb4,0x22,0xda,0x80,0x2c,0x9f,0xac,0x41};
        unsigned char   iv_aes2[AES_BLOCK_SIZE]          = {0x3d,0xaf,0xba,0x42,0x9d,0x9e,0xb4,0x30,0xb4,0x22,0xda,0x80,0x2c,0x9f,0xac,0x41};

        memset(o_sour,          0, 2048);
        memset(o_temp,          0, 2048);
        memset(o_encrypt,       0, 2048);
        memset(o_decrypt,       0, 2048);

        strcpy(editb, "{\"name\":\"hello\",\"age\":\"23\",\"name\":\"안녕\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"city\":\"air\",\"city\":\"air\",\"city\":\"air\",\"city\":\"air\",\"city\":\"air\",\"city\":\"air\",\"city\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\",\"tel\":\"010-1234-5678\",\"city\":\"air\"}");

        len = strlen(editb);
        printf("string len:[%d]\n\n", len);
        memcpy(o_sour, editb, len);

        /* 암호화               */
        p_encrypt(o_sour, o_encrypt, len, iv_aes1);
        encrypt_size = ((len + AES_BLOCK_SIZE) / AES_BLOCK_SIZE) * AES_BLOCK_SIZE;
        memcpy(o_temp, o_encrypt, encrypt_size);

        printf("[orginal]");
        p_print_byte(o_sour, encrypt_size);
        printf("[cypher]");
        p_print_byte(o_temp, encrypt_size);

        memcpy(&lastb[0], iv_aes1, AES_BLOCK_SIZE);
        memcpy(&lastb[AES_BLOCK_SIZE], o_temp, encrypt_size);

        printf("[iv + ciper]");
        p_print_byte(lastb, encrypt_size + AES_BLOCK_SIZE);

        /* 복호화               */
        p_decrypt(lastb, o_decrypt, encrypt_size, iv_aes2);

        printf("[decrypt]");
        p_print_byte(o_decrypt, encrypt_size);

        return (0);
}
