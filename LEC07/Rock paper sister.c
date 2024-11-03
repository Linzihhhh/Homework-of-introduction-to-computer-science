#include <stdio.h>
#include <math.h>
int smaller(int x, int y)
{
    if(x < y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int bigger(int x, int y)
{
    if(x > y)
    {
        return x;
    }
    else
    {
        return y;
    }
}
int play(char id[], char judge[], int player[], int n,int round)
{
    if(n == 1)
    {   
        //printf("%d\n", id[0]);
        return player[0] + 1;
        
    }
    char id2[n/2];
    int player2[n/2];
    for(int i =0; i<= n-2; i+=2)
    {
        if(id[i] == id[i+1] && judge[round] == 's')
        {
             id2[i/2] = id[i];
             player2[i/2] = smaller(player[i], player[i+1]);
        }
        else if(id[i] == id[i+1] && judge[round] == 'b')
        {
            id2[i/2] = id[i+1];
            player2[i/2] = bigger(player[i], player[i+1]);
        }
        else if(id[i] == 'p' && id[i + 1] == 's')
        {
            id2[i/2] = id[i + 1];
            player2[i/2] = player[i + 1];
        }
        else if(id [i] == 's' && id[i + 1] == 'p')
        {
            id2[i/2] = id[i];
            player2[i/2] = player[i];
        }
        else if(id [i] == 'r' && id[i+1] == 'p')
        {
            id2[i/2] = id[i+1];
            player2[i/2] = player[i+1];
        }
        else if(id[i] == 'p' && id[i+1] == 'r')
        {
            id2[i/2] = id[i];
            player2[i/2] = player[i];
        }
        else if(id[i] == 'r' && id[i+1] == 's')
        {
            id2[i/2] = id[i];
            player2[i/2] = player[i];
        }
        else if(id[i] == 's' && id[i+1] == 'r')
        {
            id2[i/2] = id[i+1];
            player2[i/2] = player[i+1];
        }
    }
    round ++;
    play(id2, judge , player2, n/2, round);
    
}
int main() {
    int n;
    scanf("%d", &n);
    int k = log2(n);
    char id[n], judge[k];
    int player[n];
    for(int i = 0; i < n; i++) {
        player[i] = i;
    }
    char blank;
    scanf("%c", &blank);
    for(int i = 0; i < n; i++) {
        scanf("%c", &id[i]);
    }
    scanf("%c", &blank);
    for(int i = 0; i < k; i++) {
        scanf("%c", &judge[i]);
        //printf("%c\n", judge[i]);
    }
    //printf("%s\n", id);
    //printf("%s\n", judge);
    printf("%d\n", play(id, judge, player, n, 0));
    return 0;
}