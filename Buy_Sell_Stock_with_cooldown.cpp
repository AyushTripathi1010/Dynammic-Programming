// LeetCode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

// INTUITION : it is similar to buy and sell stock 2 problem , with only difference
// that here after selling a stock we can't buy another stock on the next
// day, after that we can buy.

// so in the sell recursive call, we will do i+2 .
class Solution {
public:
 int solve(int i , int buy , vector<int> &prices , int &n , vector<vector<int>>&dp)
     {
        if(i >= n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[i] + solve(i+1 , 0 , prices , n , dp)
                        , solve(i+1 , 1 ,prices , n , dp));
                        
        }
        else
        {
            profit = max(prices[i] + solve(i+2 , 1 , prices , n , dp), 
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