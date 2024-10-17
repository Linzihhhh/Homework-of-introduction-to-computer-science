/*#include <stdio.h>
#define int unsigned long long
signed main () {
    int d1, d2, d3;
    scanf("%llu%llu%llu", &d1, &d2, &d3);
    int ans = (d1 * 0x38E38E38E38E3800LLU + d2 * 0x2AAAAAAAAAAAAAAALLU + 0x1C71C71C71C71C71LLU) ;
    ans = (ans % 0x7CE66C50E2840000LLU);
    printf("%llu", ans);
    return 0;
}*/
#include<stdio.h>
#include<math.h>

#define int long long

signed main () {
    char str[8];
    scanf("%s", str);
    int sum = 0;
    for(int i = 0; i <= 7; i++)
    {
        if((str[i] - 'a') <= 5 && (str[i] - 'a') >= 0)
        {
            sum += (str[i] -'a' + 10) * pow((int)16, 7 - i);
        }
        else sum += (str[i] - '0') * pow((int)16,7 - i);
        
    }
    //printf("%lld", sum);
    printf("%lld.", sum / (int)(256 * 256 * 256));
    sum %= ((int)(256 * 256 * 256));
    printf("%lld.", sum / (256 * 256));
    sum %= 256 * 256;
    printf("%lld.", sum / (int)256);
    sum %= 256;
    printf("%lld", sum);
    return 0;
}