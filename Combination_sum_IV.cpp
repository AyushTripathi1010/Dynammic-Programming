// Leetcode Link :https://leetcode.com/problems/combination-sum-iv/

// INTUITION : here we have to all possible combinations
// eg, if one of the combination is (1,1,2), then we will
// also have to take (1,2,1), (2,1,1), that is all permuations, and 
// in order to acheive this we will do a slight change in our code
// Whenever we pick an element we again start our recursion from 0 index
// so that we do not skip the element previous to it , which can satisfy 
// he give target.
class Solution {
public:
    int N;
    int solve(int idx , int target , vector<int> &nums , vector<vector<int>> &dp)
    {
        if(target == 0) return 1;
        
        // if(idx >= N) return 0;
        
        if(dp[idx][target] != -1) return dp[idx][target];

        //  int pick = 0;
        // if(target >= nums[i]) 
        // pick = solve(0 , target - nums[i] , nums, dp);

        // int not_pick = solve(i+1 , target , nums , dp);

        // return dp[i][target] = pick + not_pick;

        // ALTERNATIVE METHOD TO THE SAME

        int result = 0;

        for(int i = idx ; i <N ; i++) // handles the job of not_pick operation
        {
            if(target >= nums[i]) 
            result+= solve(0 , target - nums[i] , nums, dp); // handles the pick operation

        }
 
        return dp[idx][target] = result;
    }
    int combinationSum4(vector<int>& nums, int target) {
         
         int n = nums.size();
         N = n;
         vector<vector<int> > dp(n , vector<int> (target+1 , -1));

         return solve(0, target ,nums, dp);
    }
};