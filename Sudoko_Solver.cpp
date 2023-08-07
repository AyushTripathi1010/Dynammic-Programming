// Question:
// Given an incomplete Sudoku configuration in a 9x9 2-D square matrix (grid[][]), find a solution for the Sudoku puzzle. The Sudoku solution must satisfy the following rules:

// 1. Each digit from 1 to 9 must occur exactly once in each row.
// 2. Each digit from 1 to 9 must occur exactly once in each column.
// 3. Each digit from 1 to 9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.

// Assume that there will be only one unique solution.


class Solution 
{
public:
    // Function to check if a digit is valid in the current position.
    bool isValid(  int d, int row, int col, int grid[N][N])
    {
        for (int i = 0; i < 9; i++)
        {
            if (grid[i][col] == d) return false; // Check row possibility
            if (grid[row][i] == d) return false; // Check column possibility
            if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == d) return false; // Check 3x3 subgrid
        }
        return true;
    }
    
    // Function to solve the Sudoku using backtracking.
    bool SolveSudoku(int grid[N][N])  
    { 
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (grid[i][j] == 0)
                {
                    for (int d = 1; d <= 9; d++)
                    {
                        if (isValid( d, i, j, grid))
                        {
                            grid[i][j] = d; // Assign the valid digit to the cell
                            
                            if (SolveSudoku(grid)) return true;
                            else grid[i][j] = 0; // If the assignment doesn't lead to a solution, backtrack
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    // Function to print grids of the Sudoku.
    void printGrid(int grid[N][N]) 
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                std::cout << grid[i][j] << " ";
            }
            // std::cout << std::endl;
        }
    }
};
