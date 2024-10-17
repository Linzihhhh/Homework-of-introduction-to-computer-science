#include <stdio.h>
int graph[20][20];
int dfs(int x)
{
    int sum = 0;
    int flag = 0;
    for(int i = 0;i < 20; i++)
    {
        if(graph[x][i] == 1)
        {
            sum = dfs(i) + sum;
            flag = 1;
        }
    }
    if(flag == 0)
    {
        return 1;
    }
    else{
        return sum;
    }
}
signed main()
{
    int n;
    scanf("%d", &n);
    for(int i = 0;i <= 19; i++)
    {
        for(int j = 0;j <= 19; j++)
        {
            graph[i][j] = 0;
        }
    }
    for(int i = 0;i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if(x == 0)
        {
            continue;
        }
        else{
            for(int j = 0;j < x; j++)
            {
                int y;
                scanf("%d", &y);
                graph[i][y-1] = 1;
            }
        }
    }
    int sum = 0;
    for(int i=0;i < n; i++)
    {
        sum += dfs(i);
    }
    printf("%d", sum);
}