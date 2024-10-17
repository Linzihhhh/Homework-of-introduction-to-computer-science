#include <stdio.h>
#include <stdint.h>


void floatToBinary(float num, char *binary) {
    union {
        float input;
        int output;
    } data;
    data.input = num;

    for (int i = 31; i >= 0; i--) {
        binary[31 - i] = (data.output >> i) & 1 ? '1' : '0';
    }
    binary[32] = '\0';
}


void printBinary(char *binary) {
    for (int i = 0; i < 32; i++) {
        if (i > 0 && i % 8 == 0) {
            printf(" ");
        }
        printf("%c", binary[i]);
    }
    printf("\n");
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    float fa = (float)a;
    float fb = (float)b;

    char binaryA[33], binaryB[33], binarySum[33];

    floatToBinary(fa, binaryA);
    floatToBinary(fb, binaryB);

    int sum = *((int*)&fa) + *((int*)&fb);
    for (int i = 31; i >= 0; i--) {
        binarySum[31 - i] = (sum >> i) & 1 ? '1' : '0';
    }
    binarySum[32] = '\0';

    printf("   ");
    printBinary(binaryA);
    printf("+) ");
    printBinary(binaryB);
    printf("---------------------------------------\n");
    printf("   ");
    printBinary(binarySum);

    printf("%d + %d = %d\n", a, b, sum);

    return 0;
}