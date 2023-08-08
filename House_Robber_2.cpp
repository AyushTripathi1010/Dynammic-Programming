// Leetcode Link: https://leetcode.com/problems/house-robber-ii/
class Solution {
public:
    int solve(int i , int start, vector<int> &nums , vector<int > &dp)
    {
        if(i < start) return 0; // to handle the n-2 case
        if(i== start) return nums[i]; // to handle the n-1 case

        if(dp[i] != -1) return dp[i];

        int pick = nums[i] + solve(i - 2 , start , nums , dp);

        int not_pick = 0 + solve(i-1 ,start, nums, dp);

        return dp[i] = max(pick , not_pick);


    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        //  Edge Case
        if(n == 1) return nums[0]; // no circlular visit possible
        vector<int> dp(n+1 , -1) , dp1(n+1, -1);
        return max(solve(n-1 ,1,  nums , dp) , solve(n-2 , 0 , nums ,dp1));

    }
};