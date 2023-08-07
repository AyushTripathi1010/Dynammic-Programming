// LeetCode Link: https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
class Solution {
public:
    

    bool solve(int idx , vector<int >&nums , int &n , int k , int &target , int currsum 
    , vector<int> &vis)
    {
        if(k == 1) return true;
         

        if(currsum == target) 
        {     
        	//  reseting the target =0  and index = 0
            return solve(0 , nums , n , k-1 , target , 0  , vis);
        }

        for(int i = idx; i < n ; i++)
        {
               if(vis[i] || currsum+nums[i] > target) continue;
                vis[i] = 1;
                   
                   //  since we are picking this element so add its value and incrment the index
                if(solve(i+1 , nums , n , k, target , currsum+nums[i]  , vis))
                return true; 
                
                vis[i] = 0;
            
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int sum = 0;
        // for(int &elem : nums) sum+= elem;
        sum = accumulate(nums.begin(), nums.end(), sum);
         int n = nums.size();
         if(sum%k != 0 || n < k) return false;

         if(k == 1) return true;

        
          int target = sum/k;

          // We are taking the visited array so that
          // we do not consider the same element again
          // which has already satisfied the condition
          // in some other partition.

        vector<int> vis(n, 0);
        return solve(0 , nums , n , k , target , 0  , vis );
         

        
    }
};