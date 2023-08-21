// COding Ninja Link: https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954?leftPanelTab=0&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// INTUITION : 2 parameter are changing : index and targets
//  value.
#include <bits/stdc++.h> 

int solve(int i , int target , vector<int> &arr , vector<vector<int>> &dp)
{
    if(target == 0) return 1; // 1 means true;
    
    if(i == 0) return arr[0] == target;  // this means, return true if last element makes target 0.
    
    if(dp[i][target] != -1) return dp[i][target];
    
    int not_pick =  solve(i-1 , target ,arr , dp);
     if(not_pick == 1) return 1;
      
      int pick = 0;
     if(target >= arr[i])
     pick = solve(i-1 ,target-arr[i], arr, dp);
    if(pick == 1) return 1; 
    
   return dp[i][target] = (not_pick | pick);
    
    
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    
    vector<vector<int>> dp( n+1 , vector<int> (k+1 , -1));
    
    return solve( n-1 ,  k , arr , dp) == 1;



    // Tabulation  
    vector<vector<bool>> dp( n+1 , vector<bool> (k+1 , 0));

    for(int i =0 ; i < n ; i++) dp[i][0] = 1;
    dp[0][arr[0]] = 1; 

    for(int i =1 ; i<  n ; i++)
    {
        for(int target = 1; target <= k ; target++)
        {
            int not_pick = dp[i-1][target];
            
            
            int pick = 0;
            if(target >= arr[i])
            pick = dp[i-1][target-arr[i]];
            
            
            dp[i][target] = (not_pick | pick);
        }
    }

    return (dp[n-1][k]);



}