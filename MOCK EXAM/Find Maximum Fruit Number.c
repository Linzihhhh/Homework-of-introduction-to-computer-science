void find_fruit(char input[], char fruit[][15]){
    int n = strlen(input);
    char temp[15] = "";
    int k = 0;
    int fruitcnt[20] = {};
    for(int i = 0 ; i <= n-1;)
    {
        if(input[i] == '+')
        {
            temp[k] = '\0';
            for(int j = 0;j<= 19;j++)
            {
                if(strcmp(temp, fruit[j]) ==0)
                {
                    fruitcnt[j] ++;
                    break;
                }
            }
            i = i + 3;
            k = 0;
        }
        else
        {
            temp[k] = input[i];
            k++;
            i++;
        }
    }
    int maxn = -1e9;
    for(int i = 0; i<= 19;i++)
    {
        if(fruitcnt[i] > maxn)
        {
            maxn = fruitcnt[i];
        }
    }
    for(int i =0;i<=19;i++)
    {
        if(fruitcnt[i] == maxn)
        {
            printf("%s\n", fruit[i]);
        }
    }


}