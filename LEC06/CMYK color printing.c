#include <stdio.h>
#include <math.h>
#define MAX_SIZE 256

unsigned int W, H;
unsigned int image[MAX_SIZE][MAX_SIZE] = {0};

char layers[4] = {'C', 'M', 'Y', 'K'};

void print_C(unsigned int mask[][MAX_SIZE]);
void print_M(unsigned int mask[][MAX_SIZE]);
void print_Y(unsigned int mask[][MAX_SIZE]);
void print_K(unsigned int mask[][MAX_SIZE]);
void CMYK_to_RGB();

void print_C(unsigned int mask[][MAX_SIZE]) {
    for (int i = 0; i <= MAX_SIZE - 1; i++) {
        for (int j = 0; j <= MAX_SIZE - 1; j++) {
            image[i][j] += mask[i][j];
        }
    }
}

void print_M(unsigned int mask[][MAX_SIZE]) {
    for (int i = 0; i <= MAX_SIZE - 1; i++) {
        for (int j = 0; j <= MAX_SIZE - 1; j++) {
            image[i][j] += mask[i][j] * 256;
        }
    }
}

void print_Y(unsigned int mask[][MAX_SIZE]) {
    for (int i = 0; i <= MAX_SIZE - 1; i++) {
        for (int j = 0; j <= MAX_SIZE - 1; j++) {
            image[i][j] += mask[i][j] * 256 * 256;
        }
    }
}

void print_K(unsigned int mask[][MAX_SIZE]) {
    for (int i = 0; i <= MAX_SIZE - 1; i++) {
        for (int j = 0; j <= MAX_SIZE - 1; j++) {
            image[i][j] += mask[i][j] * 256 * 256 * 256;
        }
    }
}

void CMYK_to_RGB() {
    
    for (int i = 0; i <= MAX_SIZE - 1; i++) {
        for (int j = 0; j <= MAX_SIZE - 1; j++) {
            int K,Y,M,C;
            K = image[i][j] / (1 << 24);
            image[i][j] = image[i][j] % (1 << 24);
            Y = image[i][j] / (1 << 16);
            image[i][j] = image[i][j] % (1 << 16);
            M = image[i][j] / (1 << 8);
            image[i][j] = image[i][j] % (1 << 8);
            C = image[i][j];
            image[i][j] = 0;
            float R = 255 * (1 - C / 100.0) * (1 - K / 100.0);
            float G = 255 * (1 - M / 100.0) * (1 - K / 100.0);
            float B = 255 * (1 - Y / 100.0) * (1 - K / 100.0);
            
            image[i][j] = ((int)round(R) << 16) | ((int)round(G) << 8) | (int)round(B);

        }
    }
}

int main() {
    // Get the dimension of the image.
    scanf("%u %u", &W, &H);

    // Declare the mask for single ink color.
    unsigned int mask[MAX_SIZE][MAX_SIZE] = {0};

    // For each layer, do the following:
    for (int layer = 0; layer < 4; ++layer) {
        // Get color mask.
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                scanf("%u", &mask[i][j]);
            }
        }

        // Print a layer of that color to the paper.
        switch (layers[layer]) {
            case 'C': print_C(mask); break;
            case 'M': print_M(mask); break;
            case 'Y': print_Y(mask); break;
            case 'K': print_K(mask); break;
        }
    }

    // Convert CMYK color to RGB color.
    CMYK_to_RGB();

    // Show the final result.
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            printf("#%06x ", image[i][j]);
        }
        printf("\n");
    }

    return 0;
}
