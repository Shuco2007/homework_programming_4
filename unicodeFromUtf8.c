#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Use: %s <unicode>\n", argv[0]);
        return 1;
    }
    
    unsigned int utf8 = atoi(argv[1]);
    unsigned int result = 0;
    
    if ((utf8 & 0x80) == 0) {
        result = utf8;
    }  
    else if ((utf8 & 0xC000) == 0xC000) {
        unsigned int byte2 = utf8 & 0x3F;
        unsigned int byte1 = (utf8 >> 8) & 0x1F;
        result = (byte1 << 6) | byte2;
    } 
    else if ((utf8 & 0xF00000) == 0xE00000) {
        unsigned int byte3 = utf8 & 0x3F;
        unsigned int byte2 = (utf8 >> 8) & 0x1F;
        unsigned int byte1 = (utf8 >> 16) & 0x0F;
        result = (byte1 << 5) | (byte2 << 4) | byte3;
    } 
    else if ((utf8 & 0xF8000000) == 0xF0000000) {
        unsigned int byte4 = utf8 & 0x3F;
        unsigned int byte3 = (utf8 >> 8) & 0x1F;
        unsigned int byte2 = (utf8 >> 16) & 0x0F;
        unsigned int byte1 = (utf8 >> 24) & 0x07;
        result = (byte1 << 5) | (byte2 << 4) | (byte3 << 3) | byte4;
    }
    
    printf("%u\n", result);
    return 0;
}
