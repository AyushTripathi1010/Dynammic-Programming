// Coding Ninjas Link :https://www.codingninjas.com/studio/problems/longest-common-substring_1235207?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos 


// INTUITION : if the characters match then do 1 + dp[i-1][j-1].
// else reset dp[i][j] = 0.
int lcs(string &s, string &t){
    
	// Tabulation Method
    int n = s.size();
	int m = t.size();
    vector<vector<int>> dp(n+1 , vector<int> (m+1 , 0));

        int ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(s[i-1] == t[j-1])
			 {
				 dp[i][j]= 1 + dp[i-1][j-1];
				 ans = max(ans , dp[i][j]);
             }

			else dp[i][j] = 0;
		}
        
	}

	return ans;




	// 1-D array SPACE OPTIMISED APPROACH

	vector<int> prev(m+1, 0) , curr(m+1 , 0);

    int ans = 0;
	for(int i = 1 ; i <= n ; i++)
	{
		for(int j = 1 ; j <= m ; j++)
		{
			if(s[i-1] == t[j-1])
			 {curr[j] = 1+ prev[j-1];
               ans = max(ans , curr[j]);
             }

			else curr[j] = 0;
		}
        prev= curr;
	}

	return ans;

}