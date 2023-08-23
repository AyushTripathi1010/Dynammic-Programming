// Coding Ninjas Link : https://www.codingninjas.com/studio/problems/shortest-supersequence_4244493?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos 


// INTUITION : We have to print the shortedt supersequence , which means
// that we have to print a string which will include all the characters of
// both the strings, but the common subsequence should occur only once.
//  first create the lcs dp table then start from the last index.


#include <bits/stdc++.h> 
string shortestSupersequence(string a, string b)
{
	int n = a.size();
	int m = b.size();
	vector<vector<int>> dp(n+1 , vector<int> (m+1, 0));

    
	for(int i = 1 ; i<= n ; i++)
	{
		for(int j = 1 ; j<=m ; j++)
		{
			
			if(a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else
			dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
		}
	}

	int i = n , j = m;
	string ans="";
	//  the following will contain the common letters and some extras, but 
	// not all.
	while(i>0 && j>0)
	{
		if(a[i-1] == b[j-1])
		{
			ans+= a[i-1];
			j--,i--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) // means move up, so ignore 
		{
			ans+=a[i-1];
			i--;
		}
		else
		{
			ans+= b[j-1];
			j--;
		}

	}
    
	//  any one of the string is still not completed so add them as it is.
	while(i > 0)
	{
		ans+= a[i-1];
		i--;
	}
	while(j >0)
	{
		ans+= b[j-1];
		j--;
	}

	reverse(ans.begin() , ans.end());

	return ans;






}