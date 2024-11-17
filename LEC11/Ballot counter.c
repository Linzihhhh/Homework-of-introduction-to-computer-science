void count(const char *name)
{
    int n = 32;
	for(int i = 0;i<=n -1;i++)
    {
        if(strcmp(counter[i].name,name) ==0)
        {
            counter[i].count++;
        }
        else continue;
    }
}

const char *winner()
{
    int max = -1e9;
    char *who_win;
	for(int i = 0;i <= 32 -1 ;i++)
    {
        if(counter[i].count > max)
        {
            max = counter[i].count;
            who_win = counter[i].name;
        }
    }
    return who_win;
}