#include<stdio.h>

int main()
{
    int bingo[8][8]={0};
    for(int i=0;i<8;i++)
    {
        for(int j=0;j<8;j++)
        {
            scanf("%d",&bingo[i][j]);
        }
    }
    int ans=0;
    for(int i = 0;i <64;i++)
    {
        int x;
        scanf("%d",&x);
        for(int j=0;j<8;j++)
        {
            for(int k=0;k<8;k++)
            {
                if(bingo[j][k]==x)
                {
                    bingo[j][k]=0;
                }
            }
        }
    }
    for(int i = 0;i<8;i++)
    {
        int cnt=0;
        for(int j=0;j<8;j++)
        {
            if(bingo[i][j]==0)
            {
                cnt++;
            }
        }
        if(cnt==8)
        {
            ans++;
        }
    }
    for(int i = 0;i<8;i++)
    {
        int cnt=0;
        for(int j=0;j<8;j++)
        {
            if(bingo[j][i]==0)
            {
                cnt++;
            }
        }
        if(cnt==8)
        {
            ans++;
        }
    }
    int cnt=0;
    for(int i=0;i<8;i++)
    {
        if(bingo[i][i]==0)
        {
            cnt++;
        }
        if(cnt==8)
        {
            ans++;
        }
    }
    cnt=0;
    for(int i=0;i<8;i++)
    {
        if(bingo[i][7-i]==0)
        {
            cnt++;
        }
        if(cnt==8)
        {
            ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}