// Problem Link: https://leetcode.com/problems/partition-array-for-maximum-sum/ 


// INTUITION : same intuition as palindrome partitioning, here we have
// to partition  partition the array into (contiguous) subarrays of length 
// at most k. After partitioning, each subarray has their values changed to 
// become the maximum value of that subarray.
class Solution {
public:

    int dp[501];
    int solve(int i , int n , vector<int> &arr , int k)
    {
        if(i == n) return 0;

        if(dp[i] != -1) return dp[i];

        int curr_partition_max_elem = 0;
        int ans= 0;
        for(int j = i ; j < n ; j++)
        {
            if(j-i+1 > k) continue;  // if length exceeds the k.

            curr_partition_max_elem = max(curr_partition_max_elem , arr[j]);
            int curr_partition_sum = (j-i+1)*curr_partition_max_elem;

            int next_partition_sum = solve(j+1 , n , arr,  k);

            ans = max(ans, curr_partition_sum + next_partition_sum);


        }

        return dp[i] = ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
         
         int n = arr.size();
         memset(dp , -1 , sizeof dp);
         return solve(0 , n , arr , k);
    }
};