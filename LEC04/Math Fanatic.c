#include <stdio.h>
#define int long long
signed main () 
{
    int n, i, j;
    scanf("%lld", &n);
    int s[n];
    int prefix_sum = 0;
    for(i=0; i < n; i++)
    {
        scanf("%lld", &s[i]);   
        prefix_sum += s[i];
        if(prefix_sum % s[i] == 0)
        {
            printf("%lld %lld\n", prefix_sum, s[i]);
        }
    }
    return 0;
}