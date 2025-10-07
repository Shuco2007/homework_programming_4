#include <stdio.h>
#include <stdlib.h>

void printBinary(unsigned int num, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Use: %s <unicode>\n", argv[0]);
        return 1;
    }
    
    float num = atof(argv[1]);
    unsigned int binary = *(unsigned int*)&num;
    printBinary(binary, 32);
    
    return 0;
}