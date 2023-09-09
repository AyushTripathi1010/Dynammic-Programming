// LeetCode Link : https://leetcode.com/problems/jump-game-ii/

// INTUITION : here our target is to reach the last index
// of array , and initaly i am standing at 0th index , 
// the condition is that if i am at ith index , then i can
// make a jump of   0 =<j<= nums[i]
// a jump of 0 does not make sense so j starts with 1.

class Solution {
public:
    
    int solve(int i , vector<int> &nums, int &n , vector<int> &dp )
    {
        if(i == n-1) return 0;

        if(dp[i] != -1) return dp[i];
        int ans =n ;
        for(int j = 1 ; j<= nums[i] ; j++)
        {   
            if(i+j >=n) continue;
            ans = min(ans, 1 + solve(i+j , nums , n ,dp));
            
        }
        return  dp[i] = ans;
    }
    int jump(vector<int>& nums) {
         
         int n = nums.size();
          vector<int> dp(n+1 , -1);
          return solve(0 , nums , n , dp);
    }
};