#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("incorrect number of arguments\n");
        return 1;
    }

    unsigned int utf16 = atoi(argv[1]);
    unsigned long result = 0;

    unsigned long high = (utf16 >> 16);
    unsigned long low  = utf16 & 0xFFFF;

    if ((utf16 <= 0xD7FF) || (utf16 >= 0xE000 && utf16 <= 0xFFFF)) {
        result = utf16;
    } 
    else if (high >= 0xD800 && high <= 0xDBFF && low >= 0xDC00 && low <= 0xDFFF) {
        result = ((high - 0xD800) << 10) | (low - 0xDC00) + 0x10000;
    }
    else {
        printf("incorrect range\n");
        return 1;
    }

    printf("%lu\n", result);
    return 0;
}

//старший сурогат D800 до DBFF	55296 до 56319 
//младший сурогат DC00 до DFFF	56320 до 57343   