// Problem LINK: https://practice.geeksforgeeks.org/problems/number-of-distinct-subsequences0909/1

// INTUITION: Here we can not apply recursion and store every subsequence in set,
// because there will be 2^n subsets which is not possible to store.

// Therefore we will apply dynammic programming, using tabulation, because it 
// it is more intuitive.
// we will create a dp array, and set dp[0] = 1, which means we are storing
// empty string as our first subsequence.
// For string it will start from i = 1 to n.
// One thing to remember is that for every new character, eg:
// str = "oa", there will be 4 subsequences , i.e 2^2
// simiarly str = "oab", there will be 8 subseq., ie 2^3
// Which means for every new character the number of subsequences will be
// dp[i] = 2*dp[i-1], every time multiply by 2, because subsequeces are in 
// power of 2.

// But How to remove duplicates ?
// Eg : str = "oabac"
// In this case there will be duplicate subsequences like: "oa", "oa", "a","a"
// one 'a' is of 1st index, and other 'a' is of 3rd index.

// SO to remove duplicate, just check the number of subsequences the same character
// has made in it's  most recent previous state, which is store in dp array.
// because those same subsequences will also be made by the new occurence of that same
// character also.

// Eg if 1st 'a' occurs at 1st index, and then 'a' occurs again at 3rd index
// then dp[3] = total subsequence at dp[3] - dp[1].
 


class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int n = s.size();
	    
	    long long MOD = 1e9+7;
	    vector<long long> dp(n+1 , 0);
	    dp[0] = 1;
	    unordered_map<char , int> m;
	    
	    for(int i = 1 ; i<= n  ;i++)
	    {
	        
	        dp[i] = (2*dp[i-1])%MOD;
	        
	        char ch = s[i-1];
	        
	        if(m.count(ch))
	        {
	            int j = m[ch];
	            dp[i] = (dp[i] - dp[j] + MOD)%MOD;
	        }
	        m[ch] = (i-1);
	        
	    }
	    
	    return (int)dp[n];
	}