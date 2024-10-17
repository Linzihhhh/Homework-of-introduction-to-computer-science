#include <stdio.h>
#include <ctype.h>

int main()
{
    int n;
    scanf("%d", &n);
    char c, pc;
    int cnt1 = 0;
    pc = ' ';
    
    while(c = getchar() )
    {
        //printf("%c", c);
        if(c == '\n') continue;
        if(c == ',' || c == '.' || c == ';')
        {
            printf("\n");
            pc = ' ';
            cnt1++ ;
        }
        else if(isalpha(c))
        {
            //printf("here\n");
            if(pc == ' ' )
            {
                printf("%c", toupper(c));
            }
            else
            {
                printf("%c", tolower(c));
            }
            pc = c;
        }
        else
        {
            printf("%c", c);
            pc = c;
        }
        if(cnt1 == n) break;
    }

}