// LeetCode Link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

// INTUITION : here instead of 2, we are doing k transactions.
class Solution {
public:
int solve(int i , int buy , int cap, vector<int> &prices , int &n , vector<vector<vector<int>>>&dp)
     {
        if(cap == 0) return 0;
        if(i == n) return 0;

        if(dp[i][buy][cap] != -1) return dp[i][buy][cap];
        int profit = 0;
        if(buy)
        {
            profit = max(-prices[i] + solve(i+1 , 0 , cap ,prices , n , dp)
                        , solve(i+1 , 1 , cap , prices , n , dp));
                        
        }
        else
        {
            profit = max(prices[i] + solve(i+1 , 1 , cap-1, prices , n , dp), 
                         solve(i+1 , 0 ,cap , prices , n ,dp));
        }

        return dp[i][buy][cap] = profit;
     }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
         vector<vector<vector<int>>> dp(n , vector<vector<int>> (2, vector<int> (k+1 , -1)));
         return solve(0 , 1 , k , prices , n , dp);
    }
    
};