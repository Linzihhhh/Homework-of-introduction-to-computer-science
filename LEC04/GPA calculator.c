#include<stdio.h>
#include<math.h>
#include<ctype.h>

int maxn(int x)
{
    if(x>0) return x;
    else return 0;
}

int main () {
    float sum = 0;
    char c;
    int cnt = 0, creditNow;
    while(c = getchar())
    {
        if(c == '\n') break;
        if(isdigit(c))
        {
            cnt += (c - '0');
            creditNow = c - '0';
            continue;
        }
        if(isalpha(c))
        {
            sum += maxn(4-(c-'A')) * creditNow;
        }
        if(c == '+')
        {
            sum += 0.3 * creditNow;
        }
        if(c == '-')
        {
            sum -= 0.3 * creditNow;
        }
    }
    printf("%.2f" , (float)sum/cnt);
    return 0;
}
