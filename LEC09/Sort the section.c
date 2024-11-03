#include <stdio.h>
#define ARR_MAX 1000
void sort_section(int *ptr, int *qtr);
int main() {
  int N, a, b;
  scanf("%d%d%d", &N, &a, &b);
  int arr[ARR_MAX] = {0};
  for (int i = 0; i < N; i++) {
    scanf("%d", arr + i);
  }
  sort_section(&arr[a], &arr[b]);
  for (int i = 0; i < N; i++) {
    printf("%d ", *(arr + i));
  }
}
void sort_section(int *ptr, int *qtr) {
	if(ptr > qtr)
    {
		int *temp = ptr;
        ptr = qtr;
        qtr = temp;
    }
    int n = qtr - ptr;
    for(int i = 0 ; i <= n - 1;i ++)
    {
        for(int j = 0 ;j<= n-1; j ++)
        {
            int *b = ptr+j+1;
            int *a = ptr+j;
            if(*b < *a)
            {
                int temp = * b;
                *b = *a;
                *a = temp;
            }
        }
        for(int j = 0 ;j<= n; j ++)printf("%d ", *(ptr+j));
        printf("\n");
    }
}
