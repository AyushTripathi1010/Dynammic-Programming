// LeetCode Link : https://leetcode.com/problems/longest-increasing-subsequence/description/ 


// INTUITION : Simple, just maintain a prev_idx, parameter, to for comparing
// purpose, if i am at ith index just compare nums[i] > nums[prev_idx],
// or prev_idx == -1 , then only pick.
class Solution {
public:

    int solve(int i , int prev_idx , vector<int> &nums , vector<vector<int>>&dp)
    {
        if(i == nums.size()) return 0;
        
        if(dp[i][prev_idx+1] != -1) return dp[i][prev_idx+1];

        int not_pick = 0 + solve(i+1 , prev_idx , nums, dp);
        
        int pick =0;
        if(prev_idx == -1 || nums[i] > nums[prev_idx])
        {
            pick =   1 + solve(i+1 , i , nums , dp);
        }

        return dp[i][prev_idx+1] =  max(pick , not_pick);

    }
    int lengthOfLIS(vector<int>& nums) {
           
           int n = nums.size();
           vector<vector<int>> dp(n+1 , vector<int> (n+1, -1));
           return solve(0 , -1 , nums , dp);


           // Tabulation 
        vector<vector<int>> dp(n+1 , vector<int> (n+1, 0));

            for(int prev = 0 ; prev<= n; prev++)
         {
              dp[n][prev] = 0;
         }
        for(int i = n-1 ; i >=0 ; i--)
    {     // prev will start just before the current index.
        for(int prev = i-1 ; prev >= -1 ; prev-- )
        {
            int not_pick = 0 + dp[i+1][prev+1];

            int pick = 0;
            if(prev == -1 || arr[i] > arr[prev])
            {
                pick = 1 + dp[i+1][i+1];
            }

             dp[i][prev+1] = max(pick , not_pick);
        }
    }
        return dp[0][0];
    }
    }
};
