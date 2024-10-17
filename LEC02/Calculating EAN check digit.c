#include <stdio.h>
int main(void){
    char ean[12];
    scanf("%s", ean);
    int a = 0, b = 0;
    for(int i = 0 ; i <= 11 ; i++)
    {
        if(i % 2 == 1)
        {
        	a = a + (ean[i] - '0');
        }
        else
        {
            b = b + (ean[i] - '0');
        }
    }
    int x = a * 3 + b;
    int y = x - 1;
    int z = y % 10;
    z = 9 - z;
    printf("%d", z);
    return 0;
}
