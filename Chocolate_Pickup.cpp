// Coding Ninja Link: https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos 


// INTUITION : Approach is simple here alice and bob will move
// to next row and have 3 direction columns in which we can enter
// so here 3 parameters are changing, one is row, 2nd is Alice Column,
// 3rd is Bob's Column, and at any point both are standing at same cell
// if we accumulate that node's value only once.

#include <bits/stdc++.h> 

int solve(int row , int col1 , int col2 , vector<vector<int>> &grid , vector<vector<vector<int>>> &dp, int &n, int&m)
{    
    // if any one goes out of bound we return a samll value.
    if(row >=n || col1 < 0 || col2<0 || col1>=m || col2 >= m ) return -1e8;
    
    if(row == n-1) // when we are in last row 
    {
        if(col1== col2) return grid[row][col1]; // if both are standing in same cell, count once
        return grid[row][col1] + grid[row][col2]; 
    }
    
    if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
    
    int ans = 0;

    // Let dj1 be ALice and dj2 be Bob ,so by using the 2 loops we are saying that
    // For every moment of alice, bob can move in 3 directions .
    for(int dj1 = -1 ; dj1<=1 ; dj1++)
    {
        for(int dj2 = -1 ; dj2<=1 ; dj2++)
        {
            
            
            if(col1 == col2)  ans = max(ans , grid[row][col1] + solve(row+1, col1+dj1 , col2+dj2 , grid, dp, n, m));
            else
            {
                ans = max(ans , grid[row][col1]+ grid[row][col2] + solve(row+1, col1+dj1 , col2+dj2 , grid, dp, n, m));
            }
        }
    }
    return dp[row][col1][col2] = ans;
}
int maximumChocolates(int n, int m, vector<vector<int>> &grid) {
    // Write your code here.
    
    vector<vector<vector<int>>> dp(n , vector<vector<int>>(m, vector<int>(m, -1)));
    
    return solve(0 , 0 , m-1, grid , dp, n,m);
}