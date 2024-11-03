#include <stdio.h>
#define NUM 9
#include <stdio.h>
#define NUM 9

void check_sudoku(int (*grid_p)[NUM]);

int main(void){
    int grid[NUM][NUM]; // sudoku puzzle
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            scanf("%d", &grid[i][j]);
        }
    }
    check_sudoku(grid);
    return 0;
}
void check_sudoku(int (*grid_p)[NUM]) {
    int row_counts[NUM][NUM + 1] = {0};
    int col_counts[NUM][NUM + 1] = {0};
    int subgrid_counts[NUM][NUM + 1] = {0};
    
    // First pass to count occurrences
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            int num = grid_p[i][j];
            if(num < 1 || num > 9) continue;
            row_counts[i][num]++;
            col_counts[j][num]++;
            subgrid_counts[(i/3)*3 + j/3][num]++;
        }
    }
    
    // Check for duplicates
    for(int i = 0; i < NUM; ++i){
        for(int j = 0; j < NUM; ++j){
            int num = grid_p[i][j];
            if(num < 1 || num > 9) {
                printf("(%d,%d)\n", i, j);
                continue;
            }
            if(row_counts[i][num] > 1 || col_counts[j][num] > 1 || subgrid_counts[(i/3)*3 + j/3][num] > 1){
                printf("(%d,%d)\n", i, j);
            }
        }
    }
}