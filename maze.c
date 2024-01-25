#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 1, 0, 1, 0, 0, 0},
    {1, 1, 1, 0, 1, 0, 1, 1, 1, 1},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 0, 1, 0, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
    {0, 0, 1, 0, 1, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 0}
};

bool solveMaze(int maze[ROWS][COLS], int currentRow, int currentCol) {
    if (currentRow < 0 || currentCol < 0 || currentRow >= ROWS || currentCol >= COLS)
        return false;
    else if (maze[currentRow][currentCol] == 0) {
        maze[currentRow][currentCol] = 2;
        
        if (currentRow == ROWS - 1 && currentCol == COLS - 1)
            return true;
        else if (solveMaze(maze, currentRow + 1, currentCol) || 
                 solveMaze(maze, currentRow, currentCol + 1) ||
                 solveMaze(maze, currentRow - 1, currentCol) ||
                 solveMaze(maze, currentRow, currentCol - 1))
            return true;
        else {
            maze[currentRow][currentCol] = 0;
            return false;
        }
    }
    return false;
}

void printMaze(int maze[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    if (solveMaze(maze, 0, 0)) {
        printf("Solution found:\n");
        printMaze(maze);
    } else {
        printf("No solution found.\n");
    }
    
    return 0;
}