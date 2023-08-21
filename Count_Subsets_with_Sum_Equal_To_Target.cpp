// Coding Ninjas Link : https://www.codingninjas.com/studio/problems/number-of-subsets_3952532?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos 

// INTUITION : here we just have to find the number of ways 
// to acheive target.
#include<bits/stdc++.h>
const int MOD = 1e9 + 7;

int solve(int i , int target , vector<int> &arr , vector<vector<int>> &dp)
{
	if(target == 0) return 1;
	if(i==0)
	{
		if(arr[0] == target) return 1;
		else
		return 0;
	}
	
	
	if(dp[i][target] != -1) return dp[i][target];
	int pick = 0;
	if(arr[i] <= target) pick = solve(i-1 , target-arr[i] , arr, dp );

	int not_pick = solve(i-1 , target , arr, dp);

	return dp[i][target]= (pick + not_pick) %MOD;

}


int findWays(vector<int>& arr, int k)
{
	// Write your code here.
	int n = arr.size();
	vector<vector<int>> dp(n+1 , vector<int>(k+1 , 0));
	return solve(n-1 , k , arr , dp);



	//  TABULATION
	// fill the taget column 0 with 1. 
	for(int i =0 ; i < n ; i++)  dp[i][0] = 1 ;
	if(arr[0] <= k) dp[0][arr[0]] = 1;  // arr[0] <= k handles the overflow condition

	for(int i=  1 ; i< n ; i++)
	{
		for(int target = 1 ; target<=k ; target++)
		{
			int pick = 0;
			if(arr[i] <= target) pick = dp[i-1][target-arr[i]];

			int not_pick = dp[i-1][target];

			 dp[i][target]= (pick + not_pick) %MOD;
		}
	}

	return dp[n-1][k];



	
}
