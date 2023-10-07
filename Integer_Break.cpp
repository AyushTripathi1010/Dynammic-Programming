// Problem Link: https://leetcode.com/problems/integer-break/description/

// INTUITION: We have to break a number in more than 2 parts such that
// sum of those numbers is equal to n and we have to maximize the product.

// Eg: n = 4, then we can break it in (1, 3), then further break 3 in (1,2), then further
// break it 2 in (1,1), 
// and what ever gives the maximum product that is our answer.
class Solution {
public:
    int prod ;
    int dp[59];
    int solve(int n)
    {    
        if(n == 1) return 1;

        if(dp[n] != -1) return dp[n];
        int maxi = INT_MIN;
        for(int i = 1 ; i<= n ; i++)
        {
            int ans = i *max(n-i , solve(n-i));
            maxi = max(maxi , ans);
        }

        return  dp[n] = maxi;

    }
    int integerBreak(int n) {
         prod = 1;
        memset(dp , -1, sizeof dp);
         return solve(n);
    }
};