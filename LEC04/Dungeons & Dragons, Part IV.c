#include <stdio.h>
#include <stdint.h>
#include <limits.h>

uint32_t rotate_right(uint32_t value, unsigned int count) {
    const unsigned int mask = (CHAR_BIT * sizeof(value) - 1);
    count &= mask;
    return (value >> count) | (value << ((-count) & mask));
}

int main() {
    uint32_t N;
    int d1, d2, d3, d4;

    scanf("%u", &N);
    scanf("%d %d %d %d", &d1, &d2, &d3, &d4);

    uint32_t temp = 0;

    uint8_t bytes[4];
    bytes[0] = (N >> 24) & 0xFF;
    bytes[1] = (N >> 16) & 0xFF;
    bytes[2] = (N >> 8) & 0xFF;
    bytes[3] = N & 0xFF;

    temp |= (bytes[d1 - 1] ^ bytes[d2 - 1]) << 24;
    temp |= (bytes[d2 - 1] & bytes[d3 - 1]) << 16;
    temp |= (bytes[d3 - 1] | bytes[d1 - 1]) << 8;
    temp |= (~bytes[d4 - 1]) & 0xFF;
    temp = rotate_right(temp, d1 + d2 + d3 + d4);

    uint16_t upper = (temp >> 16) & 0xFFFF;
    uint16_t lower = temp & 0xFFFF;
    uint16_t result = upper ^ lower;

    printf("%u\n", result);

    return 0;
}
