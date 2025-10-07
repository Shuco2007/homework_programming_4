#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Use: %s <unicode>\n", argv[0]);
        return 1;
    }
    
    unsigned int unicode = atoi(argv[1]);
    unsigned int result = 0;
    
    if (unicode <= 0x7F) {
        result = unicode;
    } 
    else if (unicode <= 0x7FF) {
        unsigned int byte2 = (unicode & 0x3F) | 0x80;
        unsigned int byte1 = ((unicode >> 6) & 0x1F) | 0xC0;
        result = (byte1 << 8) | byte2;
    } 
    else if (unicode <= 0xFFFF) {
        unsigned int byte3 = (unicode & 0x3F) | 0x80;
        unsigned int byte2 = ((unicode >> 6) & 0x3F) | 0x80;
        unsigned int byte1 = ((unicode >> 12) & 0x0F) | 0xE0;
        result = (byte1 << 16) | (byte2 << 8) | byte3;
    } 
    else if (unicode <= 0x10FFFF) {
        unsigned int byte4 = (unicode & 0x3F) | 0x80;
        unsigned int byte3 = ((unicode >> 6) & 0x3F) | 0x80;
        unsigned int byte2 = ((unicode >> 12) & 0x3F) | 0x80;
        unsigned int byte1 = ((unicode >> 18) & 0x07) | 0xF0;
        result = (byte1 << 24) | (byte2 << 16) | (byte3 << 8) | byte4;
    }
    
    printf("%u\n", result);
    return 0;
}
