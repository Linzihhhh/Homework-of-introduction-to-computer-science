#include <stdio.h>
#define NUM 9

void checkSudoku(int (*gridPtr)[NUM]);

int main(void){
    int grid[NUM][NUM];
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    checkSudoku(grid);
    return 0;
}

void checkSudoku(int (*gridPtr)[NUM]) {
    int rowCounts[NUM][NUM + 1] = {0};
    int colCounts[NUM][NUM + 1] = {0};
    int subgridCounts[NUM][NUM + 1] = {0};
    
    // First pass to count occurrences
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            int num = gridPtr[i][j];
            if(num < 1 || num > 9) continue;
            rowCounts[i][num]++;
            colCounts[j][num]++;
            subgridCounts[(i/3)*3 + j/3][num]++;
        }
    }
    
    // Check for duplicates
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            int num = gridPtr[i][j];
            if(num < 1 || num > 9) {
                printf("(%d,%d)\n", i, j);
                continue;
            }
            if(rowCounts[i][num] > 1 || colCounts[j][num] > 1 || subgridCounts[(i/3)*3 + j/3][num] > 1){
                printf("(%d,%d)\n", i, j);
            }
        }
    }
}
