// Coding Ninjas Link : https://www.codingninjas.com/studio/problems/ways-to-make-coin-change_630471?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// INTUITION : this question is same as coin change problem , but 
// here we have to find the number of ways to acheive target V.
// We can pick coins of any denomination more than once.

#include<bits/stdc++.h>
long solve(int i , int target , int *denominations, vector<vector<long>> &dp)
{
    if(i == 0)
    {
        if(target%denominations[i] == 0) return 1;
        return 0;
    }
     
     if(dp[i][target] != -1) return dp[i][target];
    long pick = 0;
    if(target >= denominations[i]) pick = solve(i , target - denominations[i] ,denominations, dp);

    long not_pick = solve(i-1 , target , denominations , dp );

    return dp[i][target] = pick + not_pick;



}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    //Write your code here
    vector<vector<long>> dp(n+1, vector<long> (value+1 , -1));

    return solve(n-1 , value , denominations ,dp);

}