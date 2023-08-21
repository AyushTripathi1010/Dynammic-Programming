// Coding Ninjas Link  : https://www.codingninjas.com/studio/problems/minimum-elements_3843091?leftPanelTab=1%3Fsource%3Dyoutube&campaign=striver_dpseries&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dpseries 


// INTUITION : here all elements are distinct, and we can pick an element
// any number of times, we have to find the minimum number of elements
// that i can pick to acheive the target.
// Similar to subset sum equal to target.
#include <bits/stdc++.h> 

int solve(int i , int target , vector<int> &num , vector<vector<int>> &dp)
{
    if(target == 0) return 0;
    if(i == 0)
    {   
        // if the element is divisible by target then, i can pick that element
        // target/nums[i] times.
        if(target%num[i] == 0) return target/num[i]; 
        return 1e9;
    }
    if(dp[i][target] != -1) return dp[i][target];
    
    int pick = 1e9;
    if(num[i] <= target) pick  = 1 + solve(i , target - num[i] , num , dp);

    int not_pick = 0 + solve(i-1 , target , num , dp );

    return dp[i][target] = min(pick , not_pick);
}


int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (x+1 ,-1));

    int ans =  solve(n-1 , x , num, dp);
    if(ans >= 1e9) return -1;
    
    return ans;

    //  TABULATION

    vector<vector<int>> dp(n+1, vector<int> (x+1 ,0));
    for(int target= 0 ; target <= x ; target++) 
    {
        if(target%num[0]== 0) dp[0][target] = target/num[0];
        else
        dp[0][target] = 1e9;
        
    }

    for(int i = 1; i < n ; i++)
    {
        for(int target= 0 ; target <= x ; target++)
        {
            int pick = 1e9;
            if(num[i] <= target) pick  = 1 + dp[i][target-num[i]];

            int not_pick = 0 + dp[i-1][target];

             dp[i][target] = min(pick , not_pick);
        }
    }

    return dp[n-1][x] >= 1e9 ? -1 : dp[n-1][x];
    
    
    
}