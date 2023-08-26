// LeetCode Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/ 

// INTUITION : We first assume that we are buying the stock at 0th day itself
// then it's obvious that we will be selling stock on 1st day or ahead.
// and every time we try to sell the stock at ith day, we see behind that 
// index which the minimal value to buy stock.
class Solution {
public:
    int maxProfit(vector<int>& prices) {
            
            int minimal  = prices[0];
            
            int profit = 0;
            for(int i = 1 ; i < prices.size() ; i++)
            {
                //  if i am selling the stock at ith day.
                profit = max(profit , prices[i] - minimal);
                minimal = min(minimal , prices[i]);
            }

            return profit;
    }
};