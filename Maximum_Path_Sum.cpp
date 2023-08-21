// Coding Ninja Link : https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// INTUITION : Here we have have variable starting point and varible
// ending point so we will have to use for loop.
#include <bits/stdc++.h> 
int N , M;
int solve(int row , int col ,vector<vector<int>> &matrix ,vector<vector<int>> &dp, int &n, int &m )
{    
    if(col <0 || col >=m) return -1e8;  // if out of bound then return very small value.
    // if we have reached the first row then return the corresping value.
    if(row == n-1)
    {return matrix[row][col];
        
    }

    if(dp[row][col] != -1) return dp[row][col];

     int lft = matrix[row][col] + solve(row+1 , col-1, matrix, dp,n,m);

     int down = matrix[row][col] + solve(row+1, col, matrix, dp ,n,m);

     int rht = matrix[row][col] + solve(row+1, col+1 , matrix, dp , n,m);

     return dp[row][col] = max(lft , max(down, rht));

}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
   
    vector<vector<int>> dp( n+1 , vector<int>(m+1 , -1));
    int ans = INT_MIN;
    for(int i = 0; i < m ; i++)
    {
        ans = max(ans , solve(0 , i , matrix , dp , n, m));
    }



    //  Tabulation
    
    vector<vector<int>> dp( n+1 , vector<int>(m+1 , 0));
    //   fillong the first row of dp with first row of matrix.
     for(int i = 0; i < m ; i++) dp[n-1][i] = matrix[n-1][i];

     for(int row = n-2 ; row >= 0 ; row--)
     {
         for(int col = 0; col < m ; col++)
         {
             int lft = -1e8 , rht = -1e8 , down = -1e8;
            if(row+1<n && col-1>=0) lft = matrix[row][col] + dp[row+1][col-1];

            if(row+1< n) down = matrix[row][col] + dp[row+1][col];

            if(row+1<n && col+1 <m) rht = matrix[row][col] + dp[row+1][col+1];

             dp[row][col] = max(lft , max(down, rht));

         }
     }
        int ans = INT_MIN;
     for(int i= 0 ; i < m ; i++)
     {
            ans = max(ans , dp[0][i]);
     }

    


    return ans;
}