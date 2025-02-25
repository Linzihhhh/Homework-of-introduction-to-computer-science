#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#define WAVEFORM_HEIGHT 68

char *decodeWaveform(int **waveform, int width, int secretLength);

int main() {
    int width;
    int secretLength;

    scanf("%d", &width);
    scanf("%d", &secretLength);

    int **waveform;
    waveform = (int **)malloc(WAVEFORM_HEIGHT * sizeof(int *));
    for (int i = 0; i < WAVEFORM_HEIGHT; i++) {
        waveform[i] = (int *)malloc(width * sizeof(int));
    }

    char tmp;
    for (int i = 0; i < WAVEFORM_HEIGHT; i++) {
        for (int j = 0; j < width; j++) {
            scanf("%d", &waveform[i][j]);
            if (j != width - 1) {
                scanf("%c", &tmp);
            }
        }
    }
    
    char *secret = decodeWaveform(waveform, width, secretLength);
    printf("%s\n", secret);

    return 0;
}
char* decodeWaveform(int** waveform, int width, int secretLength) {
    char* secret = (char*)malloc((secretLength + 1) * sizeof(char));
    secret[secretLength] = '\0';
    
    int yInit = 26 + 8;  // Initial y position
    int yMin = 26;       // Minimum y value
    int yMax = 26 + 15;  // Maximum y value (26 + 16 - 1)
    int yStep = 1;       // Initial step
    int currentY = yInit;
    int foundChars = 0;
    
    // For each x position in the waveform
    int pre = 'h' - 'a';
    for (int x = 0; x < width && foundChars < secretLength; x++) {
        // Check if there's a deviation from the expected wave pattern
        int expectedY = currentY;
        
        // Look for character marking (deviation from wave pattern)

        for (int y = 0; y < WAVEFORM_HEIGHT; y++) {
            if (waveform[y][x] == 1 && y!=expectedY) {
                // Found a character marking
                secret[foundChars] =  'a' + (((y - expectedY) + pre + 2600000) %26);
                //printf("%d %d %c\n",y-expectedY, pre, secret[foundChars]);
                pre = (secret[foundChars] - 'a');
                foundChars++;
                break;
            }
        }
        
        // Update y position for next iteration
        currentY += yStep;
        
        // Check if we need to reverse direction
        if (currentY == yMin || currentY == yMax) {
            yStep = -yStep;
        }
    }
    
    return secret;
}