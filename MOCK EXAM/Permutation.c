#include <stdio.h>
int k = 0;
void recursion(char c[], int letters[], int p)
{
    if(p > 0)
    {
        for(int i = 0;i<= 26-1;i++)
        {
            if(letters[i]>0)
            {
                letters[i]--;
                c[k-p] = ('A' + i);

                recursion(c,letters, p-1);
                letters[i]++;
            }
            
        }
    }
    else if(p == 0)
    {
        c[k] = '\0';
        printf("%s\n", c);
        return;
    }
}
int main(void){
	int letters[26] = {};
    char c;
    while((c = getchar()) != EOF)
    {
        if(c == '\n') break;
        int x  = (c - 'A');
        letters[x]++;
        k ++;
    }
    char str[k];
    recursion(str, letters, k);
    return 0;
}
