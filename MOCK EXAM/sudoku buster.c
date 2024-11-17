#include <stdio.h>
#include <stdbool.h>

struct element {
    char val;        // 'A'~'Z': valid, 0: don't have value yet
    bool can_modify;       // true: white area in the figure, false: gray area in the figure
};

void solve(struct element (*grid_p)[9]);
void print_grid(struct element (*grid_p)[9]) {
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            printf("%c ", grid_p[i][j].val);
        }
        printf("\n");
    }
}

int main(void) {
    struct element grid[9][9];
    char ch;
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            scanf(" %c", &ch);
            if (ch == '.') {    // can_modify assign true, val assign 0
                grid[i][j].val = 0;
                grid[i][j].can_modify = true;
            }
            else {      // value gotten from input, so we can't change this
                grid[i][j].val = ch;
                grid[i][j].can_modify = false;
            }
        }
    }
    solve(grid);
    
    print_grid(grid);
    return 0;
}

#include <stdbool.h>

bool is_valid(struct element grid[9][9], int row, int col, char ch) {
    for (int i = 0; i < 9; i++) {
        if (grid[row][i].val == ch) return false;
        if (grid[i][col].val == ch) return false;
        int box_row = 3 * (row / 3) + i / 3;
        int box_col = 3 * (col / 3) + i % 3;
        if (grid[box_row][box_col].val == ch) return false;
    }
    return true;
}

bool solve_helper(struct element grid[9][9], int row, int col) {
    if (row == 9) return true;
    if (col == 9) return solve_helper(grid, row + 1, 0);
    if (!grid[row][col].can_modify) return solve_helper(grid, row, col + 1);

    for (char ch = 'A'; ch <= 'I'; ch++) {
        if (is_valid(grid, row, col, ch)) {
            grid[row][col].val = ch;
            if (solve_helper(grid, row, col + 1)) return true;
            grid[row][col].val = 0;
        }
    }
    return false;
}

void solve(struct element (*grid_p)[9]) {
    solve_helper(*grid_p, 0, 0);
}