// Coding Ninja Link : https://www.codingninjas.com/studio/problems/minimum-path-sum_985349?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos 


// INTUITION : Approach is simple, find the minimum path sum
// to reach destination , there can be multiple paths to reach destination
// but we want path with minimum sum .
// WE will travrse all the paths and if any time we go out
// of bound , we will return a large Value, so that it does
// not affect our minimum sum at any instant.
#include <bits/stdc++.h> 

int solve(int row , int col, vector<vector<int>> &grid , vector<vector<int>> &dp )
{
    if(row == 0&& col == 0) return grid[row][col];
    if(row < 0 || col < 0) return 1e8;
    if(dp[row][col] != -1) return dp[row][col];

    // int lft =0 , up = 0;
     int  lft =  grid[row][col] + solve(row , col-1 , grid , dp);

     int  up = grid[row][col] + solve(row-1 , col , grid, dp);

     return dp[row][col] = min(lft , up );




}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
     int n=  grid.size();
     int m = grid[0].size();
    //  vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1));

    //  return solve(n-1, m-1, grid , dp);

    //   Tabulation
    vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0));
    dp[0][0] = grid[0][0];
    for(int row = 0; row < n ; row++)
    {
         for(int col = 0; col  < m;  col++)
         {      
             if(row== 0 && col == 0) continue;
               int lft = 1e8 , up = 1e8;
                if(col-1 >=0) lft =  grid[row][col] + dp[row][col-1];

                 if(row-1>=0) up = grid[row][col] + dp[row-1][col];

                 dp[row][col] = min(lft , up );
         }
    }

    return dp[n-1][m-1];
       
}