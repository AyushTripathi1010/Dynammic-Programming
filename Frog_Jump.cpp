// Coding Ninjas: https://www.codingninjas.com/studio/problems/frog-jump_3621012?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

#include <bits/stdc++.h> 

// int solve(int i , vector<int>&heights , vector<int>&dp)
// {
//     if(i == 0) return 0;
//     if(dp[i] != -1) return dp[i];
//     int lft = abs(heights[i-1]- heights[i]) + solve(i-1 , heights , dp);
//         int rht = INT_MAX;
            
//         if (i - 2 >= 0) {
//           rht = abs(heights[i - 2] - heights[i]) + solve(i - 2, heights, dp);
//         }

//         return dp[i] = min(lft , rht);
// }
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
       
       // Recursion + Memoization
      vector<int> dp(n+1 , -1);
      
      return solve(n-1 , heights , dp);

      // Tabulation
        vector<int> dp(n , 0);
        dp[0] = 0;

        for(int i = 1 ; i < n ; i++)
        {
          int lft = abs(heights[i-1]- heights[i]) + dp[i-1];
          int rht = INT_MAX;

          if (i - 2 >= 0) {
            rht = abs(heights[i - 2] - heights[i]) + dp[i-2];
          }

           dp[i] = min(lft , rht);
        }

        return dp[n-1];


        // Space optimised
        
        int prev1 = 0, prev2 = 0;

        for(int i = 1 ; i < n ; i++)
        {
          int lft = abs(heights[i-1]- heights[i]) + prev1;
          int rht = INT_MAX;

          if (i - 2 >= 0) {
            rht = abs(heights[i - 2] - heights[i]) + prev2;
          }
          
           int curr = min(lft , rht);

           prev2 = prev1;
           prev1= curr;
        }

        return prev1;


















        }