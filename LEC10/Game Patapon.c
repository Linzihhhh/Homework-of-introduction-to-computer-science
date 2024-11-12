    #include<stdio.h>
    #include<string.h>
    int checkSame(char c1[], char c2[])
    {
        if(strlen(c1) != strlen(c2)) return 0;
        else 
        {
            int flag = 0;
            for(int i = 0; i <= strlen(c2) -1 ;i ++)
            {
                if(c1[i] == c2[i]) continue;
                else{
                    flag = 1;
                    break;
                }
                
            }
            if(flag == 0) return 1;
            else return 0;
        }
    }
    int main () {
        int dis,blood;
        scanf("%d%d", &dis, &blood);
        char c;
        char str1[1000] = "PATA PATA PATA PON\0";
        char str2[1000] = "PON PON PATA PON\0";
        char str3[1000] = "CHAKA CHAKA PATA PON\0";
        char buffer[10000]="";
        int l=0, r = 0;
        int cnt = 0;
        int legal = 0;
        scanf("%c",&c);
        char word[100000]="";
        int k =0;
        c = ' ';
        while(c!='\n')
        {
            scanf("%c",&c);
            word[k] = c;
            k++;
        }
        for(int j = 0; j <= k-1;j++)
        {
            c = word[j];
            if(c == ',' || c == '.' || c == '\n')
            {
                cnt ++;
                char command[1000];
                int t = 0;
                int flag = 0;
                for(int i = l; i <= r;i++)
                {
                    command[t] = buffer[i];
                    t++;
                }
                command[t] = '\0';
                //printf("%s\n",command);
                //printf("%d\n",checkSame(command,str1));

                l = r;
                
                if(checkSame(command,str1))
                {
                    dis--;
                    legal ++;
                }
                else if(checkSame(command,str2))
                {
                    if(dis <= 3) blood--;
                    legal ++;
                }
                else if(checkSame(command,str3))
                {
                    dis++;
                    flag = 1;
                    legal++;
                }
                if(dis == 0)
                {
                    printf("NO %d", blood);
                    return 0;
                }
                if(blood == 0)
                {
                    printf("YES %d", legal);
                    return 0;
                }
                if((cnt) % 10 == 0)
                {
                    if(!flag)
                    {
                        printf("NO %d",blood);
                        return 0;
                    }
                }
                
                if(c == '\n')
                {
                    +
                    printf("NO %d",blood);
                    return 0;
                }
                if(cnt == 30 )
                {
                    printf("NO %d",blood);
                    return 0;
                }
            }
            else
            {
                buffer[r] = c;
                r++;
            }
        }
        return 0;
    }