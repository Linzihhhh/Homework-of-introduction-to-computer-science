#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main () {
    int humanBlood = 100, dragonBlood = 100;
    int a[6] = {};
    while((humanBlood > 0) && (dragonBlood > 0))
    {
        int sum = 0;
        for(int i = 0; i <= 5; i++)
        {
            int x;
            scanf("%d", &x);
            a[i] = x;
            
            if(i <= 2)sum += a[i];
        }
        if((sum % 2) == 1)
        {
            if(a[3] < a[4] && a[4] < a[5]) dragonBlood -= 25;
            else if(((a[3] % 2) ==(a[4] % 2)) || ((a[5] % 2) ==(a[4] % 2))) dragonBlood -= 5;
            else dragonBlood -= 0;     
        }
        else
        {
            if(abs(a[3] - a[4]) > a[5]) humanBlood -= 15;
            else if((a[3] + a[4]) != a[5]) humanBlood -=5;
            else humanBlood -= 0;
            
        }
         
    }
    if(humanBlood > 0) printf("Player wins");
    else printf("Dragon wins");
    return 0;
}
