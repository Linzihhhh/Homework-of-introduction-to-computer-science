#include <stdio.h>
#include <stdbool.h>
#define MAX_LEN 200000

int N;
char str[MAX_LEN];

void find_orz(int orz_position[], int *orz_num);
void calculate_worship(int worship_amount[], int range_index, int left_orz_position, int right_orz_position);
int find_max_worship_range(int value, int *range_L, int *range_R, int left_orz_position, int right_orz_position);

int main()
{
    scanf("%d", &N);
    scanf("%s", str);

    int orz_position[MAX_LEN] = {0}, worship_amount[MAX_LEN] = {0}, orz_num = 0;
    find_orz(orz_position, &orz_num);

    for (int i = 1; i < orz_num; i++)
    {
        calculate_worship(worship_amount, i - 1, orz_position[i - 1], orz_position[i]);
    }

    int max_worship, range_L, range_R;
    for (int i = 0; i < orz_num - 1; i++)
    {
        max_worship = find_max_worship_range(worship_amount[i], &range_L, &range_R, orz_position[i], orz_position[i + 1]);
    }
    printf("%d %d %d\n", max_worship, range_L, range_R);
}

    void find_orz(int orz_position[], int *orz_num){
        int n = N;
        char temp[3] = "";
        temp[1] = str[0];
        temp[2] = str[1];
        for(int i = 2;i <= n-1;i++)
        {
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = str[i];
            //printf("%s\n", temp);
            if(temp[0] == 'o' && temp[1] == 'r' && temp[2] == 'z')
            {
                orz_position[*orz_num] = i - 1;
                (*orz_num) ++;
                //printf("%d\n", i - 2);
            }
            
        }
    return ;
    }

    void calculate_worship(int worship_amount[], int range_index, int left_orz_position, int right_orz_position){
        int k = 0; 
        int p = 0;
        int letters[26] = {};
        for(int i = left_orz_position + 2; i < right_orz_position - 1 ; i++)
        {
            int t = str[i] - 'a';
            if(!letters[t])
            {
                p++;
                letters[t] = 1;
            }
            k++;
        }
        worship_amount[range_index] = k * p;
        //printf("%d %d  %d %d\n",k , p , left_orz_position, right_orz_position);
    }

    int find_max_worship_range(int value, int *range_L, int *range_R, int left_orz_position, int right_orz_position){
        int k = 0; 
        int p = 0;
        int letters[26] = {};
        for(int i = (*range_L) + 2; i < *(range_R) -1; i++)
        {
            int t = str[i] - 'a';
            if(!letters[t])
            {
                p++;
                letters[t] = 1;
            }
            k++;
        }
        int valueplus = k * p;
        //printf("%d %d %d\n", valueplus , left_orz_position, right_orz_position);
        if(value > valueplus)
        {
            (*range_L) = left_orz_position;
            (*range_R) = right_orz_position ;
            //printf("%d %d %d\n", value , left_orz_position, right_orz_position);
            return value;
        }
        else return valueplus;
    }