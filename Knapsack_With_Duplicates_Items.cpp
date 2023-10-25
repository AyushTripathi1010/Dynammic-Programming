// Problem Link: https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1

// INTUITION: Here we can pick a element multiple times, here only important thing is the base case.
// when we reach index 0, then we check if weight of that element is smaller than targetW, then we take it 
// targetW/wt[0] times and multiply it with its value.

class Solution{
public:
   
    int solve(int i , int targetW , int  *val , int *wt, vector<vector<int>>&dp)
    {   
        
        if(i == 0)
        {
            if(wt[0] <= targetW) return val[0]*(targetW/wt[0]);
            
            return 0;
        }
        
        // if(i < 0) return 0 // alternative base case.
        
        if(dp[i][targetW] != -1) return dp[i][targetW];
        
        int take = 0;
        if(wt[i] <= targetW)
        {
            take = val[i] + solve(i, targetW-wt[i] , val , wt, dp);
        }
        
        int not_take = 0+  solve(i-1, targetW , val , wt, dp);
        
        return dp[i][targetW] = max(take, not_take);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        
        vector<vector<int>> dp(N+1,vector<int>(W+1,-1));
        return solve(N-1, W, val, wt, dp);
    }
};