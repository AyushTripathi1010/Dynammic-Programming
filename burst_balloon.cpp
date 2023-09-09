// Leetcode Link : https://leetcode.com/problems/burst-balloons/

//  INTUITION : here if we burst a balloon, then 
// in cost we add nums[i-1] *nums[i]*nums[i+1], but the problem here is 
// that we can't directly say that pick an index and then, 
// call recursion for left partition and right partition seperately
// as they are dependent on each other. 
// So our strategy is to start from last when only one balloon will be there
// in that case , and then move up , where 2 ballons where there
// now the second balloon can be any of the remaining ballons, 
// so pick them one by one using left partition and right partition
// as done in rod cutting problem.


class Solution {
public:
    int solve(int l, int r ,  vector<int> &nums, vector<vector<int>>&dp )
    {
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];
        int maxi = 0;
        for(int i = l  ; i<= r ; i++)
        {
        int cost = nums[r+1]* nums[i]* nums[l-1] +  solve(l , i-1, nums ,dp) + solve(i+1 , r, nums , dp);
        maxi  = max(maxi , cost);
        
        }

        return dp[l][r] = maxi;
    }

    int maxCoins(vector<int>& nums) {
            
            int n = nums.size();
            nums.push_back(1);
            nums.insert(nums.begin() , 1);
            int m = nums.size();
            vector<vector<int>> dp(m+1 , vector<int> (m+1 , -1));
            return solve(1 , n , nums , dp);
    }
};