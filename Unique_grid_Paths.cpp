// Coding Ninjas: https://www.codingninjas.com/studio/problems/total-unique-paths_1081470?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 

int solve(int row , int col , vector<vector<int>>&dp)
{
    if(row == 0 && col ==0) return 1;
    
    //  if getting out of bound then return 0 ways.
    if(row < 0 || col < 0) return 0;
     if(dp[row][col] != -1) return dp[row][col];
     int lft = solve(row , col-1, dp);
     
     int up = solve(row-1 ,col, dp);
     
     return dp[row][col] = lft + up; // sum all the ways.
     
}
int uniquePaths(int m, int n) {
	// Write your code here.
       
       // Recursion + Memo
      vector<vector<int>> dp(m+1 , vector<int>(n+1 , -1));
      return solve(m-1 , n-1, dp);

    //    Tabulation
     vector<vector<int>> dp(m+1 , vector<int>(n+1 , 0));
       dp[0][0] = 1;
       
       for(int row =0  ; row < m ; row++)
       {
           for(int col =0 ; col < n ; col++)
           {   
               if(row == 0 && col== 0) continue;
               int lft = 0, up =0 ;
               
               if(col-1>=0) lft+= dp[row][col-1];
               if(row-1>=0) up = dp[row-1][col];

               dp[row][col] = lft + up;
           }
       }

       return dp[m-1][n-1];
    
}