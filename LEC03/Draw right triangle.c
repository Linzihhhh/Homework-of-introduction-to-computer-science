#include<stdio.h>

int main () {
    int i, j;
    scanf("%d%d", &i, &j);
    if(i == 1)
    {
        for(int a = 0; a <=j-1; a++)
        {
            for(int b = j; b >= 0; b--)
            {
                if(b > a)printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }
    if(i == 4)
    {
        for(int a = 0; a <=j-1; a++)
        {
            for(int b = 0; b <= j - 1; b++)
            {
                if(j - b - 1 <=  a)printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }
    if(i == 3)
    {
        for(int a = 0; a <=j-1; a++)
        {
            for(int b = 1; b <= j; b++)
            {
                if(b > a)printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }
    if(i == 2)
    {
        for(int a = 0; a <=j-1; a++)
        {
            for(int b = 0; b <= a; b++)
            {
                if(b >= 0)printf("*");
                else printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
