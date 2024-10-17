#include<stdio.h>

int main () {
    double p = 1.0;
    for(int i = 0; i <= 5 - 1; i++) {
        // printf("%lf\n", p);
        double x;
        scanf("%lf", &x);
        p *= x;
    }
    printf("%.15lf", p);
    return 0;
}
