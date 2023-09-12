// Problem Link : https://leetcode.com/problems/perfect-squares/ 

// INTUITION : for any n just loop till it's square root,
// and since we can pick any perfect square any number of times, so
// pick it and for every updated n , the loop will only consider
// perfect square number smaller than updated n.


class Solution {
public:
    int dp[10001];
    int solve(int n)
    {
        if(n == 0) return 0;

        if(dp[n] != -1) return dp[n];
         int minCount = INT_MAX;
        for(int i = 1 ; i*i <= n ; i++)
        {
            int count = 1 + solve(n - i*i);
            minCount  = min(minCount , count);

        }

        return dp[n] = minCount;
    }
    int numSquares(int n) {
           
           memset(dp , -1 , sizeof dp);
           return solve(n);
    }
};