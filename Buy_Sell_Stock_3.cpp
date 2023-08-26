// Leetcode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

// INTUITION : here at most 2 transactions can happen , so we will consider
// this transaction value as maximal weight capacity as done in 0/1 knapsack.
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

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
         vector<vector<vector<int>>> dp(n , vector<vector<int>> (2, vector<int> (3 , -1)));
         return solve(0 , 1 , 2 , prices , n , dp);
    }
};