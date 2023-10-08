// Problem Link: https://leetcode.com/problems/apply-operations-to-make-two-strings-equal/

// INTUITION: Here the code has similar recurrence to that of a lcs problem , here we have 2 options, 
// either we can flip 2 bits and add cost = x, to it, or we can take the difference between the indices of the bits
// to flip.

// Note: We are always flippig 2 bits, so if length of vector is odd, that means it is not possible to make str1= str2.

// Case1: says that take first 2 flips from vector and take their cost by adding their index difference. and then increment
// to i+2, for swapping next 2 pairs.

// Case 2: says the same thing as case 1,but this time start from last index, and take difference of v[j] - v[j-1] + solve(i, j-2);

// The questions arises is why we are doing the same thing from last index, when already done once from starting ?
// Ans.) take the example: v = [1, 4, 6, 8] and let i be at index 0, and j be at 2.
// we can either consider pair (1,4) where flipping bit will cost 4-1 = 3.
// or consider pair(4,6) which gives me cost of 2, so here when taking from reverse gives us the minimum cost.
// Therefore both are important.

// Case 3: take the 2 elements, add cost = x + solve(i+1, j-1), because it might happen considering cost x
// can give us less cost, we keeping i and j at extreme positions so that bits at maximum distance can be flipped with cost x, if x is less than that 
// distance.

class Solution {
public:
     int dp[502][502];
    int solve(int i , int j , vector<int> &v , int &x)
    {
        if(i >= j ) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // case 1: taking v[i] and moving to i+2
          
          int opt1 = (v[i+1] - v[i]) + solve(i+2 , j , v , x);

        // case 2: taking v[m-1] and moving j-2;

          int opt2 = (v[j] - v[j-1]) + solve(i , j-2, v, x);

        // case 3: taking cost x and taking random element

          int opt3 = x + solve(i+1 , j-1 , v , x);

          return dp[i][j] = min(min(opt1 , opt2) , opt3);

        
    }
    int minOperations(string s1, string s2, int x) {
          vector<int> v;
          int n = s1.size();
          

          for(int i= 0 ; i < n ; i++)
          {
              if(s1[i] != s2[i])
              v.push_back(i);
          }

          int m = v.size();
          if(m&1) return -1;  // for odd length not possible.
          memset(dp , -1 , sizeof dp);
          return solve(0 , m-1 , v , x);
    }
};