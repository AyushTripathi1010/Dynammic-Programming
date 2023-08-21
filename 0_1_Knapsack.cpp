// Coding Ninjas Link : https://www.codingninjas.com/studio/problems/0-1-knapsack_920542?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// INTUITION: The basic concept of 0/1 knapsack is either 
// to include the item in the bag or exclude it
// but we can only include the item if it weight is smaller than
// the current Maximal Weight.
// and we have ot find the maximum value that we can get.
#include <bits/stdc++.h> 

int solve(int i , vector<int> &weight , vector<int>&value , int W, vector<vector<int>>&dp)
{
	if(i == 0)
	{
		if(weight[0] <= W) return value[0];
		return 0;
	}

	// alternative of above but will not help in tabulation purpose.
	// if(i < 0) return 0;
	if(dp[i][W] != -1) return dp[i][W];

	int pick = INT_MIN;
	 if(weight[i] <= W) pick = value[i] + solve(i-1 , weight , value, W - weight[i], dp);

	  int not_pick = 0 + solve(i-1 , weight , value , W, dp);

	  return dp[i][W] = max(pick , not_pick);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
     
	//   here is dp is has 2 parameter 1 : indexing and 2: maximal weight.
	vector<vector<int>> dp(n+1 , vector<int> (maxWeight+1 , -1));
	return solve(n-1 , weight , value , maxWeight, dp );



	//  TABULATION
	vector<vector<int>> dp(n+1 , vector<int> (maxWeight+1 , 0));
	for(int wts = weight[0] ; wts <= maxWeight ; wts++) dp[0][wts] = value[0];

	for(int i = 1 ; i< n ; i++)
	{
		for(int W = 0 ; W<= maxWeight ; W++)
		{
			int pick = INT_MIN;
			if(weight[i] <= W) pick = value[i] + dp[i-1][W - weight[i]];

			int not_pick = 0 + dp[i-1][W];

			 dp[i][W] = max(pick , not_pick);

		}
	}

	return dp[n-1][maxWeight];

	  
}