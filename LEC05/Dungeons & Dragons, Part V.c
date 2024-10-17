#include <stdio.h>

int main () {
    int d[6]={0};
    for(int i=0;i<75;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(y%2 ==1)
        {
            d[x-1]++;
        }
        else
        {
            d[x-1]--;
        }

    }
    for(int i=0;i<6;i++){
        if(d[i]>=0){
            printf("%d ",d[i]%10);
        }
        else
        {
            printf("%d ",(1000000+d[i])%10);
        }
    }
    return 0;
}
