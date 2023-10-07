// Problem Link: https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/

// INTUITION : This problem is a variant of LIS, we got to know about
// it when we observerd that in the question to acheive search_cost, which can be only acheived
// when we get a greater element in future every time, which means our subsequence should be strictly
// increasing in nature.
// m depicts the range of numbers we can use that is 
// eg: m = 3, means, nos. from 1 to 3 can be used.

// We don't need to make an array, we can simply just increment the idx, every time which represents
// that we utilised one more space of our imaginary array,
// k means lis should be of length k.
// n means our array shouble be of length n.
// so we can also insert smaller numbers in between, if we are able to acheive the search cost.

// We have to use 3 parameters, n, k, maximum_till_now
// maximum_till_now : helps us to make our lis.


// At every position we are trying out all numbers from 1 to m.
// because it is possible that we have acheived k at some step, but still array is not complete
// so for that reason we will use smaller numbers in order to maintain k, and fill the array.
// Therefore we will try all possible combination.
class Solution {
public:
    
    int M, N;
    int search_cost;
    int dp[51][51][102];
    const int MOD = 1e9+7;
    int solve( int idx , int k, int maximum_till_now)
    {    
         if(idx == N)
         {
             if(k == search_cost)
             return 1;

             return 0;
         }
         if(dp[idx][k][maximum_till_now+1] != -1) return dp[idx][k][maximum_till_now+1]; 
         int ways = 0;
        for(int i = 1 ; i<= M ; i++)
        {  
            if(i > maximum_till_now)
           ways= (ways +solve(idx+1 , k+1 , i))%MOD;
           else
           ways= (ways +  solve(idx+1 , k , maximum_till_now ))%MOD;
        }
        return dp[idx][k][maximum_till_now+1] = ways;
    }
    int numOfArrays(int n, int m, int k) {
        
          M = m;
          N = n;
          search_cost = k;
          memset(dp , -1, sizeof dp);
          return solve(0, 0, -1);
    }
};