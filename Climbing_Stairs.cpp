// https://leetcode.com/problems/climbing-stairs/submissions/789518526/
class Solution {
public:
    int  f(int i, vector<int> &dp)
    {
            
        
           if(i<=2) return i;  // if i = 1 return 1, or if i = 2, return 2.
            if(dp[i] != -1) return dp[i];

            //  go 1 step backward and also try to go 2 steps backward.
        return dp[i] = f(i-1 ,dp) + f(i-2 ,dp);    
        
        
        
    }
    int climbStairs(int n) {
         vector<int> dp(n+1, -1);
         return f(n ,dp);
    
    }
};