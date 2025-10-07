#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("incorrect number of arguments");
        return 1;
    }

    unsigned int unicode = atoi(argv[1]);
    unsigned int result = 0;

    if ((unicode <= 0xD7FF) || (unicode >= 0xE000 && unicode <= 0xFFFF)) {
        result = unicode;
    } 
    else if (unicode >= 0x10000 && unicode <= 0x10FFFF) {
        unicode -= 0x10000;
        unsigned int high = 0xD800 + (unicode >> 10);
        unsigned int low  = 0xDC00 + (unicode & 0x3FF);
        result = (high << 16) | low;
    }
    else {
        printf("incorrect range");
        return 1;
    }
    printf("%u\n", result);
}