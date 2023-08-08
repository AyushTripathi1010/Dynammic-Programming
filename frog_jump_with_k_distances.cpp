// Questions :
// Here we have options to go backward by k steps, when standing at a position,
// rather than having options to go only  1 or 2 stepss


#include <bits/stdc++.h> 

int solve(int idx , vector<int>&heights , vector<int>&dp, int &k)
{
    if(i == 0) return 0;
    if(dp[i] != -1) return dp[i];
      int mini = INT_MAX;
      for(int j = 1 ; j<= k ;j++)
      {
      	 int ans = INT_MAX;
      	 if(idx-j>=0)
      	 	ans = abs(heights[idx] - heights[idx-j])+ solve(j -k , heights , dp , k);
         mini = min(mini , ans);
      }

        return dp[i] = mini;
}
int frogJump(int n, vector<int> &heights, int k)
{
    // Write your code here.
       
       // Recursion + Memoization
      vector<int> dp(n+1 , -1);
      
      return solve(n-1 , heights , dp, k);















        }