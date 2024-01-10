// Problem Link: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

// INTUITION: Here we have to find the count of all subsequnces, that satisfy the condition such that the sum of the minimum and maximum element on it is less or equal to target.
// Input: nums = [3,5,6,7], target = 9
// Output: 4
// Explanation: There are 4 subsequences that satisfy the condition.
// [3] -> Min value + max value <= target (3 + 3 <= 9)
// [3,5] -> (3 + 5 <= 9)
// [3,5,6] -> (3 + 6 <= 9)
// [3,6] -> (3 + 6 <= 9)

// So here we might first think of using dp,as it is talking of subsequences, but since the questions, only focuses on mini and maxi, in a particular subsequence, so
// it can be solved using 2 pointers, where we can sort the array first, and then keep one pointer 'l' at starting index and, 'r' pointer at last index, and then just
// increment and decrement l and r pointer based on the conditon, to calculate power, we have precomputed it.

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
           
           int n = nums.size();
            int MOD = 1e9+7;
           vector<int> power(n);
           power[0] = 1;
           for(int i = 1; i < n; i++)
           {
               power[i] = (power[i-1]*2)%MOD;
           }

           sort(nums.begin(), nums.end());

           int l = 0, r = n-1;
           int ans =0;
           while(l <= r)
           {
               if(nums[l] + nums[r] <= target)
               {
                   ans = (ans%MOD + power[r-l]%MOD)%MOD;
                   l++;
               }
               else
               r--;
           }

           return ans;
    }
};