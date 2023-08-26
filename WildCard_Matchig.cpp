// LeetCode Link : https://leetcode.com/problems/wildcard-matching/description/

// INTUITION : so we have to check whether the whole string A is matching with
// string B , but the with some extra conditions that string A can have 
// ? - which means it can match with any single character
// * - which means it can match with 0 length or any length substring in B,
// possibly the whole string.

// we have done shifting of index in our recursion and tabulation code.

// in case of '*' we will write 2 recursive calls, 1st call for when the *
// matches with 0 length in string B, which means just do i-1, j.

// 2nd is if matched with 1 length substring of B then do  i, j-1,

// these 2 calls will cover all the cases for * with 1,2,3,,n length substring.


class Solution {
public:
    bool solve(int i , int j  ,string &s , string &p ,vector<vector<int>> &dp)
    {
        // base case
          if(i == 0 && j == 0) return true;
          if(j== 0 && i> 0) return false;
          if(i == 0 && j>0) 
          {    
          	// Edge Case if pattern string is still not exhausted, then
          	// we can return true only if the remaining substring only contains
          	// *, because it can match to 0 length substring,
          	// oher wise return false.
              for(int k =1 ; k<=j ; k++) 
              {
                  if(p[k-1] != '*') return false;
              }
              return true;
          }

          if(dp[i][j] != -1) return dp[i][j];

        // if matching character
        if(s[i-1] == p[j-1] || p[j-1] == '?')
        return dp[i][j] = solve(i-1 , j-1 , s , p , dp);

        // case for star
        if(p[j-1] == '*')
        {
         return dp[i][j] = solve(i-1 , j , s , p , dp) || solve(i , j-1 , s , p , dp);
        }

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
           
           int n = s.size();
           int m = p.size();
           vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
           return solve(n , m , s , p , dp);


           

        //     Tabulation

        vector<vector<bool>> dp(n+1 , vector<bool>(m+1 , 0));

        dp[0][0] = true;
        for(int i = 1 ; i <= n ; i++) dp[i][0] = false;

        for(int j = 1 ; j<= m ; j++)
        {    bool flag = true;
            for(int k =1 ; k<=j ; k++) 
              {
                  if(p[k-1] != '*') {
                      flag = false;
                      break;
                  }
                  
              }
              dp[0][j] = flag;
              
        }

        for(int i = 1 ; i <= n ; i++ )
        {
            for(int j = 1;  j <= m ; j++)
            {
                // if matching character
                if(s[i-1] == p[j-1] || p[j-1] == '?')
                dp[i][j] = dp[i-1][j-1];

                // case for star
                else if(p[j-1] == '*')
                {
                     dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }

                else
                {
                    dp[i][j] = false;
                }
            }
        }

        return  dp[n][m];


    }
};