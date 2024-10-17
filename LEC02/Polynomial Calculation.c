#include <stdio.h>

int main(void){
    float x;
    scanf("%f", &x);
    float result = 0.0f;
    result = result + 7 * x * x * x * x;
    result = result - 8 * x * x * x;
    result = result - x * x;
    result = result + 6 * x;
    result = result - 22;
    printf("%.1f", result);
    return 0;
}
