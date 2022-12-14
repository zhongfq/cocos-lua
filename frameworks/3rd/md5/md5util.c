#include "md5util.h"

#include <stdio.h>

const unsigned char HEX[16] = {
    '0', '1', '2', '3',
    '4', '5', '6', '7',
    '8', '9', 'a', 'b',
    'c', 'd', 'e', 'f'
};

static void tohex(unsigned char *result, unsigned char *digest)
{
    size_t i;
    for (i = 0; i < MD5_DIGEST_LENGTH; ++i) {
        int t = digest[i];
        int a = t / 16;
        int b = t % 16;
        *result++ = HEX[a];
        *result++ = HEX[b];
    }
    *result = '\0';
}

bool md5str(unsigned char result[MD5_STR_LEN], const char *str, size_t len)
{
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5_CTX ctx;
    MD5Init(&ctx);
    MD5Update(&ctx, str, (unsigned int)len);
    MD5Final(digest, &ctx);
    tohex(result, digest);
    
    return true;
}

bool md5f(unsigned char result[MD5_STR_LEN], const char *filepath)
{
    MD5_CTX ctx;
    char buf[1024];
    size_t len;
    unsigned char digest[MD5_DIGEST_LENGTH];
    
    FILE *file = fopen(filepath, "rb");
    
    if (!file) {
        return false;
    }
    
    MD5Init(&ctx);
    while ((len = fread(buf, sizeof(char), 1024, file)) > 0) {
        MD5Update(&ctx, buf, (unsigned int)len);
    }
    MD5Final(digest, &ctx);
    tohex(result, digest);
    
    fclose(file);
    
    return true;
}
