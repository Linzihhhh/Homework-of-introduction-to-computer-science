#include<stdio.h>
#include<math.h>

int main () {
    float a;
    scanf("%f", &a);
    float A = 1.7320508f * a * a / 4;
    printf("%.3f", A);
    return 0;
}
