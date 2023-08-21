// Coding Ninja Link : https://www.codingninjas.com/studio/problems/partition-equal-subset-sum_892980?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

// INTUITION : the question asks to partition the array
// into 2 equal subset sum, so this problem is simialr to
// subset sum equal to target, but here we will do sum/2.
// and this will be our target.
 int f(int i , int target, vector<int> &nums  , vector<vector<int>> &dp)
    {   
        if(target == 0) return 1;

        if(i==0) return nums[0] == target;
        
        if(dp[i][target] != -1) return dp[i][target];
        int pick =0;
        if(nums[i]<=target)
        pick = f(i-1 , target - nums[i] , nums , dp );
        
        int non_pick = f(i-1 ,target , nums , dp);
        
        return dp[i][target] = (pick | non_pick);
        
        
    }
bool canPartition(vector<int> &nums, int n)
{
	// Write your code here.
    
    int sum =0;
        for(auto elem  : nums) sum+=elem;
        
        if(sum%2) return false;
        
        
         vector<vector<int> > dp(n , vector<int> (sum/2+1 , -1));
         return f(n-1, sum/2 ,nums , dp) == 1;
        


        //  Tabulation : 

         for(int i =0 ; i < n ; i++) dp[i][0] = true;
//         dp[0][nums[0]] = true;
        

         for(int i =1  ; i  < n ; i++)
         {
             for(int target = 1; target <=new_sum ; target++)
             {
                       bool pick =false;
                       if(nums[i]<=target)
                       pick = dp[i-1][target-nums[i]];

                       bool non_pick = dp[i-1][target];

                       dp[i][target] = pick|non_pick;

             }
         }
        
        return dp[n-1][new_sum];

}
