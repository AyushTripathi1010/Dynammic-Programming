// Coding Ninjas Link : https://www.codingninjas.com/studio/problems/target-sum_4127362?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// INTUITION:  here it is asking us to build an expression using + and -
// which on concatenating gives us the target.

// So what is the approach : here we can observe that some elements
//  will belong to + subset and some to - subset. So if 
// Subset S1 constains positive elements and subset s2 contains 
// negative elements
// therefore => S1 - S2 = target , and S2 = totalSum - S1.
// which boils down to the same question previously done.

#include <bits/stdc++.h> 

int solve(int i , int T , vector<int> &arr , vector<vector<int>> &dp)
{
    if(i == 0)
    {
        if(T == 0 && arr[i] == 0) return 2;
        if(T == 0 ||  arr[i] == T) return 1;
        return 0;
    }

    if(dp[i][T] != -1) return dp[i][T];
    
    int pick =0 ;
    if(T >= arr[i]) pick = solve(i-1 , T-arr[i] , arr , dp);
    
    int not_pick = solve(i-1 , T, arr, dp);
    
    return dp[i][T] = pick + not_pick;
    
}
int targetSum(int n, int target, vector<int>& arr) {
    // Write your code here.
    
    
    int totsum = 0;
    for(int i =0 ; i < n ; i++) totsum+= arr[i];
     
     if(totsum - target < 0 || (totsum - target)%2) return 0;
    int T = (totsum - target) / 2;
    vector<vector<int>> dp(n+1 , vector<int> (T+1, -1));
    
    
    return solve(n-1 , T , arr , dp);
}
