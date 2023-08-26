// LeetCode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/ 

// INTUITION : here we just have to deduct a fee, which can be deducted either 
// at the time of buying or at time of selling, 
// eg: if selling a stock gives me a profit of Rs.10, then Rs will be deducted
// from 10Rs as a fee.

class Solution {
public:
 int solve(int i , int buy , vector<int> &prices , int &n , vector<vector<int>>&dp,int &fee)
     {
        if(i == n) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[i] + solve(i+1 , 0 , prices , n , dp, fee)
                        , solve(i+1 , 1 ,prices , n , dp, fee));
                        
        }
        else
        {
            profit = max(prices[i]-fee + solve(i+1 , 1 , prices , n , dp, fee), 
                         solve(i+1 , 0 , prices , n ,dp, fee));
        }

        return dp[i][buy] = profit;
     }
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
         vector<vector<int>> dp(n , vector<int> (2, -1));
         return solve(0 , 1 , prices , n , dp, fee);
    }
};