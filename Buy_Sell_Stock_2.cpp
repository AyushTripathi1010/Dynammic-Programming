// LeetCode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/


// INTUITION : here we can buy and sell stock multiple times, but to buy 
// another stock we will first have to sell the stock in hold, then only 
//  we can buy another stock.

// so 2 parameters are changing , 1st is index and 2nd is buy or not buy.
// so 1 - means buy
//    0 - means sell
//    if we have bought now we will change the 2nd parameter to 0, i.e sell

class Solution {
public:
     
     int solve(int i , int buy , vector<int> &prices , int &n , vector<vector<int>>&dp)
     {
        if(i == n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[i] + solve(i+1 , 0 , prices , n , dp)
                        , solve(i+1 , 1 ,prices , n , dp));
                        
        }
        else
        {
            profit = max(prices[i] + solve(i+1 , 1 , prices , n , dp), 
                         solve(i+1 , 0 , prices , n ,dp));
        }

        return dp[i][buy] = profit;
     }
    int maxProfit(vector<int>& prices) {
         
         int n = prices.size();
         vector<vector<int>> dp(n , vector<int> (2, -1));
         return solve(0 , 1 , prices , n , dp);
    }
};