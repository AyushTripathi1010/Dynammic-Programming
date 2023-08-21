// CODING NINJA LINK : https://www.codingninjas.com/studio/problems/maze-obstacles_977241?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos 

// INTUITION : Approcach is simple, if we ever get an obstacle
// of out of bound condition we return 0 and if we reach destination
// then return 1 way.

#include<bits/stdc++.h>
const int MOD = 1e9+7;
int solve(int row , int col, vector< vector< int> > &mat , vector< vector< int> > &dp )
{
    if(row == 0 && col== 0) return 1;   // we have reached destination so return 1 way.
    if(row < 0 || col < 0) return 0;    // if getting out of bound then return 0 way.
    if(mat[row][col] == -1) return 0;   // if there is an obstacle then return 0 way.


    if(dp[row][col] != -1) return dp[row][col]; 

     int lft = solve(row , col-1 , mat , dp);

     int up = solve(row-1, col , mat, dp);

     return dp[row][col] = (lft+ up)%MOD;

}
int mazeObstacles(int n, int m, vector<vector< int>> &mat) {
    // Write your code here
    //  Edge case: What if -1 is present at starting or ending point
      if(mat[0][0] == -1 || mat[n-1][m-1] == -1) return 0;

    vector<vector<int>> dp(n+1 , vector<int> (m+1 ,-1));

    return solve(n-1 , m-1 , mat, dp);

}