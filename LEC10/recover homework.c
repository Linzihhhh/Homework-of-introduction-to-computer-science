
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 4096

void recovery(char *homework);

int main () {
    char homework[MAX_LEN + 1];
    
    // Get the homework content.
    fgets(homework, MAX_LEN , stdin);
    recovery(homework);

    // Print the recovered homework.
    fputs(homework, stdout);

    return 0;
}
void recovery(char *homework) {
    int n = strlen(homework);
    int now = 0;
    int ok[n];
    for(int i = 0;i<n;i++)
    {
        ok[i] = 0;
    }
    for(int i = 0; i<= n-1;i++)
    {
        char c = *(homework+i);
        if(c == ' ' || i == n-1)
        {
            int valid = 1;
            char temp[10000] = "";
            int k = 0;
            for(int j = now ;j <= i;j++)
            {
                temp[k] = *(homework+j);
                k++;
                
            }
            //printf("%s\n",temp);
            if(strlen(temp) > 22 || strlen(temp) < 2)
            {
                valid = 0;
            }
            if(valid)
            {
                if(strlen(temp) == 2)
                {
                    if(!isalpha(*(temp)) )
                    {
                        valid = 0;
                    }
                }
                for(int j = 0; j <= strlen(temp) - 2; j++)
                {
                    //printf("here%d\n",valid);
                    if(!isalpha(*(temp + j)))
                    {
                        if(j == strlen(temp) - 2)
                        {
                            if(*(temp + j) == '.' || *(temp + j) == ',' || *(temp + j) == '!' || *(temp + j) == '?')
                            {
                                continue;
                            }
                            else
                            {
                                valid = 0;
                            }
                        }
                        else
                        {
                            valid = 0;
                        }
                    }
                }
            }

            if(valid == 0)
            {
                for(int j = now;j <= i;j++)
                {
                    ok[j] = 1;
                }
            }
            now = i + 1;
        }
    }

    char ans[10000];
    int k = 0;
    for(int i =0;i<=n-1;i++)
    {
        if(ok[i] == 0)
        {
            ans[k] = *(homework+i);
            k++;
        }
    }
    for(int i = 0;i<=k-1;i++)
    {
        *(homework+i) = ans[i];
    }
    *(homework+k) = '\0';

}
