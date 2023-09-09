// Leetcode Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/


// INTUITION : here we will have to include the 0 and n 
// in the cuts array to determine the length of rod before it's
// partitioning , and then cut the rod.

// Don't forget to sort so that partion can be done
// independently.
class Solution {
public:  
      
      int dp[103][103];
     int solve(int l, int r,  vector<int> &cuts)
     {
            if(r-l == 1) return 0;

            if(dp[l][r] != -1) return dp[l][r];
                int ans = INT_MAX;
            for(int i = l+1;  i<=r-1; i++)
            {
                int cost = (cuts[r] - cuts[l]) + solve(l, i, cuts) + solve(i, r, cuts);

                ans = min(ans, cost);
            }

            return dp[l][r] = ans;
     }
    int minCost(int n, vector<int>& cuts) {
           
        //    first insert the starting and the end point the in cuts array,
        //  so that we can find the length.
            // N = n;
            memset(dp, -1 , sizeof dp);
           cuts.push_back(n);
           cuts.insert(begin(cuts), 0);

           sort(begin(cuts), end(cuts));
           
          return  solve(0, cuts.size()-1, cuts);

    } 
};