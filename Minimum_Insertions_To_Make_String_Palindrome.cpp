// LeetCode Link : https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/ 


// INTUITION : So we have to find the minimum insertions required to make the
// string palindrome. 
// If we are able to find the longest palindromic subsequence, then we can 
// easily subtract the length of string by length of lps.
class Solution {
public:

    int solve(int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp)
    {
        if( i == 0 || j == 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

         if(s1[i-1] == s2[j-1]) 
         return dp[i][j] = 1+  solve(i-1, j-1 , s1 , s2 , dp);

         return dp[i][j] = 0 + max(solve(i-1 , j , s1 , s2 , dp) , solve(i, j-1 , s1 ,s2, dp));
    }
    int minInsertions(string s1) {
          
          string s2 = s1;
          reverse(s2.begin() , s2.end());
          int n = s1.size();
          vector<vector<int>>  dp(n+1 ,vector<int> (n+1 , -1));
          int lps = solve(n , n , s1 ,s2 , dp);

          return n - lps;

    }
};