// Problem Link: https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1 

// INTUTITION:  approach is simple, that any fibonacci number is sum of
// it's 2 previous numbers to it. just break the problem again 
// and again, untill base condition is reached.
class Solution {
  public:
    const int MOD = 1e9+7;
    
    vector<int> dp;
    int solve(int n)
    {
        
        if(n == 0) return 0;
        if(n == 1 || n== 2) return 1;
        if(dp[n] != -1) return dp[n];
        return dp[n]= (solve(n-1) + solve(n-2))%MOD;
    }
    int nthFibonacci(int n){
        
        dp.resize(n+1 , -1);
        return solve(n);
    }
};