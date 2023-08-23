// Coding Ninjas Link: https://www.codingninjas.com/studio/problems/can-you-make_4244510?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

// INTUITION : The minimum number of insertions require to convert string A -> B
// is equal to = INSERTIONS + DELETIONS.
//  for which we will first find lcs, because lcs will remain unchanged.
#include<bits/stdc++.h>
int solve(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp)
    {
        if( i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

         if(s1[i-1] == s2[j-1]) 
         return dp[i][j] = 1+  solve(i-1, j-1 , s1 , s2 , dp);

         return dp[i][j] = 0 + max(solve(i-1 , j , s1 , s2 , dp) , solve(i, j-1 , s1 ,s2, dp));
    }
int canYouMake(string &s1, string &s2){
    // Write your code here.
          
          int n = s1.size();
          int m = s2.size();
          vector<vector<int>>  dp(n+1 ,vector<int> (m+1 , -1));
          int lcs = solve(n , m , s1 ,s2 , dp);

          int deletions = n - lcs;
          int insertions = m - lcs;
          return deletions + insertions;
}