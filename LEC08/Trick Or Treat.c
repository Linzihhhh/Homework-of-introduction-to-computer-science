#include<stdio.h>
#include<stdlib.h>
int array[1500];
int maxChandy( int size) ;
int main() {
    int size = 0;
    scanf("%d", &size);
    for(int i = 0 ; i < size; ++i) {
        scanf("%d", &array[i]);
    }
    printf("%d\n", maxChandy(size));
    return 0;
}

int maxChandy(int size) {

    int dp[size]={};
    dp[0] = array[0];
    dp[1] = (array[0] > array[1]) ? array[0] : array[1];
    if(size == 1) return array[0];
    if(size == 2) return (array[0] > array[1]) ? array[0] : array[1];
    for(int i = 2 ;i <= size -1;i++)
    {
        if(dp[i - 2] + array[i] > dp[i-1])
        {
            dp[i] = dp[i - 2] + array[i];
        }
        else dp[i] = dp[i-1];
        //printf("%d\n", dp[i]);
    }
    return dp[size-1];
}
