// Coding Ninja Link: https://www.codingninjas.com/studio/problems/triangle_1229398?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// INTUITION : Since we can have a pramid structure ,so rather
// than starting from bottom, we can start from top because
// only one node is present .

// Note: We can also start from bottom but we have to use for loop
// and consider every node for recursion call.
#include<bits/stdc++.h>

int solve(int row ,int col,  int &n , vector<vector<int>>& triangle, vector<vector<int>>&dp)
{
	if(row == n-1) return triangle[row][col];
	
	if(dp[row][col]  !=-1) return dp[row][col];
	
	int opt1 = triangle[row][col] + solve(row+1, col , n , triangle, dp);

	int opt2 = triangle[row][col] + solve(row+1, col+1 , n , triangle, dp);

	return dp[row][col] = min(opt1 , opt2);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.

	// vector<vector<int> >dp(n , vector<int> (n , -1));

	//  return solve(0 ,0, n , triangle, dp);

	//   Tabulation

	  vector<vector<int> >dp(n , vector<int> (n , 0));
	  
	  for(int i =0 ; i < n ; i++) dp[n-1][i] = triangle[n-1][i];

	  for(int row = n-2 ; row>=0 ; row--)
	  {
		  for(int col = 0; col< n; col++)
		  {
			  int opt1 = triangle[row][col] + dp[row+1][col];

			  int opt2 = triangle[row][col] + dp[row+1][col+1];

			  dp[row][col] = min(opt1 , opt2);
		  }
	  }

	  return dp[0][0];

}