// Problem Link: https://leetcode.com/problems/max-dot-product-of-two-subsequences/ 

// INTUITION: Question has similar recurrence to LCS problem, here we are pick one element from 
// nums1 and other from nums2, then doing i+1, j+1.
// then keeping i, at same place and incrementing j. SO that we can consider all possible pairs.

// Base Case: here we are returning very small value, because, it might be possible that max product that we are getting
// is negative so, so negative value will be considered while taking maximum.

// Also one more point that we have already some product with us, and we are solving our recurrence further, then when
// the array goes out of bound we are returning -1e9, which when added to our answer will give a wrong answer.
// so for that case we are taking max(0, solve(i+1, j+1)).

class Solution {
public:
    int N, M;
    int dp[501][501];
    int solve(int i , int j , vector<int> &nums1 , vector<int> &nums2)
    {
        if(i >= N || j >= M) return -1e9;

        if(dp[i][j] != -1) return dp[i][j];

        // int ans = INT_MIN;
        int opt1 = (nums1[i] * nums2[j]) + max(0, solve(i+1 ,j+1, nums1, nums2));
        
        int opt2 = 0 + max(solve(i+1, j, nums1, nums2) , solve(i ,j+1, nums1, nums2));
        
        return dp[i][j] = max(opt1, opt2);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
           N = nums1.size();
           M =  nums2.size();
           memset(dp , -1 , sizeof dp);
           return solve(0 , 0, nums1 , nums2);
    }
};