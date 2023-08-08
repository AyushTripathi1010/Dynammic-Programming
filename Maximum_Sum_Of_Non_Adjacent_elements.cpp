// Coding Ninjas: https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos 

#include <bits/stdc++.h> 

int  f(int n , vector<int> &dp , vector<int> nums)
{     
      //  base case if reaches at 0th index.
     if(n==0) return nums[0] ;
    
       if(dp[n]!=-1) return dp[n];
       //  pick the element and skip the adjacent element so decrement by 2
      int pick = 0;
          if(n-2>=0) pick = nums[n] + f(n-2,dp ,nums);
              
       int not_pick =  f(n-1 , dp ,nums);
       
       return dp[n] = max(pick , not_pick);
    
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
      int n = nums.size();

      // Recursion + Memo
       vector<int> dp(n , -1);
       return f(n-1 , dp , nums);

       // Tabulation
      vector<int> dp(n);
      dp[0] = nums[0];
    for(int i =1 ; i <n ;i++)
    {   
        int pick = nums[i];
        if(i-2>=0) pick = pick + dp[i-2];
        
        int not_pick = dp[i-1];
        
        dp[i] = max(pick , not_pick);
    }
    
    return dp[n-1];
}