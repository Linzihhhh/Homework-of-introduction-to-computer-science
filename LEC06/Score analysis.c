#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
    }
    for(int i = 0; i < n2; i++)
    {
        R[i] = arr[m + 1 + i];
    }
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

int lowerBinarySearch(int x, int arr[], int n)
{
    int minn = 0, maxn = n-1;
    while(minn <= maxn)
    {
        int mid = (minn + maxn) / 2;
        if(arr[mid] < x)
        {
            minn = mid + 1;
        }
        else
        {
            maxn = mid - 1;
        }
    }
    return minn;
}

int upperBinarySearch(int x, int arr[], int n)
{
    int minn = 0, maxn = n-1;
    while(minn <= maxn)
    {
        int mid = (minn + maxn) / 2;
        if(arr[mid] > x)
        {
            maxn = mid - 1;
        }
        else
        {
            minn = mid + 1;
        }
    }
    return minn;
}

int main()
{
    int n;
    scanf("%d", &n);
    int score[n];
    for(int i = 0;i <= n-1; i++)
    {
        scanf("%d", &score[i]);
    }
    int q;
    scanf("%d", &q);
    mergeSort(score, 0, n-1);
    /*
    for(int i = 0; i <= n-1; i++)
    {
        printf("%d ", score[i]);
    }*/

    for(int i = 0 ;i <= q-1; i++)
    {
        int x,y;
        scanf("%d%d", &x, &y);
        int a = lowerBinarySearch(x, score, n);
        int b = n - lowerBinarySearch(y, score, n);
        printf("%d ", a);
        printf("%d ", n - a - b);
        printf("%d\n", b);
    }
    
}
