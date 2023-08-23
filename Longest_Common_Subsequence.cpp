// Coding Ninjas Link : https://www.codingninjas.com/studio/problems/longest-common-subsequence_624879?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


//  INTUITION : For 2 given strings we have to find the longest common
// subsequence.
//  eg : S1 = abcd , S2 = acbd
//  so we will keep 2 pointers for each string at the last index
// then first check if both are same, then decrement both
// if not then 2 possibilites are there, 1st, decrement i, and let
// j remain as it is.
// 2nd is decrement j and let remain i at same index.


#include<bits/stdc++.h>

int solve(int i , int j , string &s , string &t , vector<vector<int>> &dp)
{   
	// if(i < 0 || j < 0) return 0;

	// alternative, by shifting of index, then keep pointer at n and m.
	// not n-1 and m-1.
	if(i == 0 || j == 0) return 0;
	
	if(dp[i][j] != -1) return dp[i][j];

	if(s[i-1] == t[j-1])
	return dp[i][j] = 1+ solve(i-1, j-1, s ,t, dp);

	return dp[i][j] = 0 + max(solve(i-1 , j , s , t, dp) , solve(i , j-1 , s ,t, dp));

}


int lcs(string s, string t)
{
	//Write your code here
	int n = s.size();
	int m = t.size();
	vector<vector<int>> dp(n+1 , vector<int> (m+1 , -1));

	return solve(n, m, s , t, dp);

	

	//  Tabulation'
	vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));

	for(int j = 0; j <= m ; j++) dp[0][j] =0;
	for(int i= 0 ; i <= n ; i++) dp[i][0] = 0;

	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(s[i-1] == t[j-1])
			 dp[i][j] = 1+ dp[i-1][j-1];

			else dp[i][j] = 0 + max(dp[i-1][j] , dp[i][j-1]);
		}
	}

	return dp[n][m];




}