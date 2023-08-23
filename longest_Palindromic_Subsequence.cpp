// LeetCode Link : https://leetcode.com/problems/longest-palindromic-subsequence/ 


// INTUITION : Here we have to find te longest palindromic subsequence, for
// which we will make another string by reversing the original string.
// and then find the longest common subsequence.
// because reversing won't affect the palindrome.
class Solution {
public:
    int solve(int i , int j , string &s1 , string &s2 , vector<vector<int>>&dp )
    {
        if(i ==0 || j ==0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i-1] == s2[j-1])
        return dp[i][j] = 1 + solve(i-1 , j-1 , s1 , s2 , dp);

        return dp[i][j] = 0 + max(solve(i-1 , j , s1, s2 ,dp) , solve(i , j-1 , s1 , s2 , dp));


    }


    int longestPalindromeSubseq(string s1) {
         
         string s2 = s1;
         reverse(s2.begin() , s2.end());
         int n = s1.size();
         vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1));

         return solve(n , n , s1, s2,dp );

        //  Tabulation
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , 0));
        
        for(int i =1 ; i<= n ; i++)
        {
            for(int j = 1 ; j<=n ; j++)
            {
                if(s1[i-1] == s2[j-1])
                 dp[i][j] = 1 + dp[i-1][j-1];

                else dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
            }
        }

        return dp[n][n];




    }
};