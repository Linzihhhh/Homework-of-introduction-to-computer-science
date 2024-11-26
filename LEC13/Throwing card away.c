#include<stdio.h>
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    int deque[10000] ={};
    int front = 5000;
    int rear = 5000;
    for(int i = 1; i <= n; i++){
        deque[rear++] = i;
    }
    for(int i = 0; i < m; i++){
        printf("%d ",deque[front]);
        deque[front] = 0;
        front ++;
        deque[rear++] = deque[front];
        deque[front] = 0;
        front++;
    }

    return 0;
}
