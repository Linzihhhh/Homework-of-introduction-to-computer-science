#include<stdio.h>
int N;

void solve(int *A, int *B, int *op_cnt);
void solve(int *A, int *B, int *op_cnt){
	for(int i = 0;i <=(1<<17)-1;i++)
    {
        int *a= A+i;
        int *b= B+i;
        if(*a >= *b) continue;
        else 
        {
            (*op_cnt)++;
            int temp = *a;
            *a = *b;
            *b = temp;
        }
    }
}
int main(){
    int A[1<<17] = {0};
    int B[1<<17] = {0};
    int op_cnt = 0;

    scanf("%d", &N);
    for(int i = 0; i<N; i++)
        scanf("%d", &A[i]);
    for(int i = 0; i<N; i++)
        scanf("%d", &B[i]);

    solve(A, B, &op_cnt);
    printf("%d\n", op_cnt);
    for(int i = 0; i<N; i++)
        printf("%d ", A[i]);
}