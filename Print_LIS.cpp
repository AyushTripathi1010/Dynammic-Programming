// GFG LINK: https://practice.geeksforgeeks.org/problems/printing-longest-increasing-subsequence/1


// INTUITION : here we creating a dp table, where dp[i] , represents what is 
// is the longest length of LIS ending at the ith index.

// The outer i loops iterate from 0 -> n, and the prev_idx iterates from 0 -> i-1
// and we keep on updating the dp table.

// But to get the path of elements of LIS we are using hash array, which initially
// stores index as it's parent, and whenever dp table get updated , we store in
// the hash table that which previous element has contributed to increase the length,
// of the current element.

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        
        // Using Tabulation
        
        vector<int> dp(n, 1);
        vector<int> hash(n);
        
        int last_index = 0;
        for(int i = 0 ; i < n ; i++)
        {   
            hash[i] = i;
            for(int prev_idx = 0 ; prev_idx < i ; prev_idx++)
            {
                if(arr[i] > arr[prev_idx] && 1+dp[prev_idx] > dp[i])
                {
                    dp[i] = 1 + dp[prev_idx];
                    hash[i] = prev_idx;
                }
                
                
            }
            if(dp[i] > dp[last_index])
                {
                    last_index = i;
                }
        }
        
        // Now it is time to backtrack from the last index to it's origin path
        
        vector<int> ans;
        
         while(hash[last_index] != last_index)
         {
             ans.push_back(arr[last_index]);
             last_index = hash[last_index];
         }
        
         ans.push_back(arr[last_index]);
         
         reverse(ans.begin() , ans.end());
        
    
        
        
         return ans;
        
        
    }
};