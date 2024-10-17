#include<stdio.h>

int main () {
    float x[6] = {};
    float y[6] = {};
   	float h[6] = {};
    scanf("%f", &x[0]);
    for(int i = 1; i <= 5; i++){
        h[i] = 0.9 * x[i-1] + 0.1*h[i-1] - 51;
        y[i] = -0.98 * h[i] + 153;
        x[i] = y[i];
    }
    for(int i = 1; i <= 5; i++)
    {
        printf("%.1f ", x[i]);
    }
    
    return 0;
}
