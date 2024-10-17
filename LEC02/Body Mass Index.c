#include<stdio.h>

int main () {
    int height, weight;
    scanf("%d %d", &height, &weight);
    float bmi = ((float)weight)/(((float)height/100)*((float)height/100));
    printf("%.6f", bmi);
    
    return 0;
}
