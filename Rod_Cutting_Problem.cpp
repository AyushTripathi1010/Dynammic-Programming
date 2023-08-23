// Coding Ninjas Link : https://www.codingninjas.com/studio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos 


//  INTUITION : so here we have to cut the rod such that we get the maximum 
//  price and cost of each length is given to us in the cost array.
//  the Rod lengh is initially N units and each length of rod has 
// infinite supply that is we can pick a particular peice of length 
// as many times till, it's in the boundation. 

// So we will first try to take the whole length of rod which is N , then
// start breaking it down into N-1, N-2, and so on.
// solve(4, 12) means that we are at index 4, which is rod length of 5 units
// and the length of rod we have currently at this instance is 12 units.

// Here 2 parameters are changing, one is index, and 2nd is what rod length
// we have with us right now.
// Similar to Knapsack where we were given a maximal weight, a and we used 
// to decrease it. 

#include<bits/stdc++.h>

int solve(int i , int N , vector<int> &price, vector<vector<int>>&dp )
{
	if(i ==0)
	{
		
		return N*price[0]; // at i = 0, rod length = 1, and if at this point suppose N = 12 , then it means
		                   // that how many rod peices of length 1 unit are needed to make it of length N = 12
		                   // so the cost of length of 1 unit *N.
		                   // simple unitary method.
	}
	
	if(dp[i][N]!= -1) return dp[i][N];
        int rodLength = i+1;
	int pick = 0;
	if(N>= rodLength)
	{
		
		pick = price[i] + solve(i , N - rodLength , price , dp);

	}
	int not_pick = 0+ solve(i-1 , N , price , dp);

	return dp[i][N] = max(pick , not_pick);
}
  
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
        vector<vector<int>> dp(n+1, vector<int> (n+1 , -1));
	return solve(n-1, n ,  price, dp);

	//  Tabulation
	vector<vector<int>> dp(n+1, vector<int> (n+1 , 0));
    
	for(int N =0 ; N <= n ; N++) dp[0][N] = N*price[0];

	for(int i = 1 ; i < n ; i++)
	{
		for(int N = 0 ; N<= n ; N++ )
		{
			int rodLength = i+1;
			int pick = 0;
			if(N>= rodLength)
			{
				
				pick = price[i] + dp[i][N-rodLength];

			}
			int not_pick = 0+ dp[i-1][N];

			 dp[i][N] = max(pick , not_pick);
		}
	}

	return dp[n-1][n];


}
