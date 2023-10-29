// Problem Link: https://leetcode.com/problems/longest-palindromic-substring/

// INTUITION: SO here we have to print the long palindromic substring, The approach taht we are goiing ti use is
// based on naive approach, that is generate all possible substrings, using 2 loops and for each substring check whether it 
// is palindrome or not. This time rather that using iterative method we have used recursive method to check whether the substring is
// palindroe or not. 

// How does memoization comes into picture. 
// Consider eg: s= "aaaaaaaa", so here n = 8, i = 0, j=0.

// Now while generating substrings suppose we reach a case where i =0 , j = 5.
// and now we check this particular substring. So what the recursive function will
// do is solve(0,5) -> solve(1,4) -> solve(2,3).

// anw again in loop suppose i am at position where i = 1, j =4, but from our previous results we have seen 
// that we would  call the same function for that subtring again, due to overlapping sub-problems.
// So here we can store the state as dp[i][j] -> which is substring i to j is palindrome or not.
// SO that we don't check again.
class Solution {
public:
    int dp[1001][1001];
    bool solve(string &s, int i , int j)
    {
        if(i >=j) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == s[j])
        {
            return dp[i][j] = solve(s, i+1, j-1);
        }

        return dp[i][j]= 0;
    }
    string longestPalindrome(string s) {
            
            int n = s.size();
            memset(dp, -1, sizeof dp);
            
            int start = -1, max_len = 0;

            for(int i= 0 ; i < n ; i++)
            {
                for(int j =0 ; j < n ; j++)
                {
                    if(solve(s,i,j) == true) // if palindrome
                    {
                        if(j-i+1 > max_len)
                        {
                            start= i;
                            max_len = j-i+1;
                        }
                    }
                }
            }

            return s.substr(start, max_len);
    }
};