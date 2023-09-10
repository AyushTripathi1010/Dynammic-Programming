// Problem Link : https://leetcode.com/problems/palindrome-partitioning-ii/ 


// INTUITION : here we have to just do the minimum cuts such that each partion
// is a palindrome in itself. so we just start partioning from 0th index,
// and at every step check whether it is palindrome or not. If it is a
// palindrome we further make recursive call for the next partition.
class Solution {
public:

    int dp[2001];
    bool isPalindrome(int i , int j , string &s)
    {
        while(i < j)
        {
            if(s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int solve(int i, int n, string &s)
    {   
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];
        
        string temp = "";
        int mini = INT_MAX;
        for(int j = i  ; j < n ; j++)
        {
            temp+= s[j];
            if(isPalindrome(i , j , s))
            {
                int cuts = 1 + solve(j+1 , n ,s);
                mini = min(mini , cuts);
            }
        }
        return dp[i] = mini;
    }
    int minCut(string s) {
         
         int n = s.size();
         memset(dp , -1 , sizeof dp);
         return solve(0 , n ,s) - 1;
    }
};