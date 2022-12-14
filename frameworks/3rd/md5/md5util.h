#ifndef __MD5UTIL_H__
#define __MD5UTIL_H__

#include <stdio.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif
    
#include "md5.h"
    
#define MD5_STR_LEN (MD5_DIGEST_LENGTH * 2 + 1)
    
bool md5str(unsigned char result[MD5_STR_LEN], const char *str, size_t len);
bool md5f(unsigned char result[MD5_STR_LEN], const char *filepath);

#ifdef __cplusplus
}
#endif

#endif
