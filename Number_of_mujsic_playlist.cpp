// Leetcode link : https://leetcode.com/problems/number-of-music-playlists/

// // INTUITION : The goal is to find the number of distinct playlists of length
//  goal that can be created using n different songs, with the constraint that the
//  same song cannot appear in consecutive positions in the playlist, and there 
//  should be at least k songs between any two occurrences of the same song.

// The main recursive steps:

// PICK: We choose a song for the current position in the playlist. There are n choices
//  for the first position, n - 1 for the second, and so on. So, we multiply 
//  solve(n - 1, goal - 1, k, dp) by n to count all valid playlists when we 
// pick a song for the current position.

// NOT PICK: We do not choose a song for the current position. In this case, 
// we can select any song from the remaining max(n - k, 0) songs 
// (to ensure there are at least k songs between repeated songs). 
// So, we multiply solve(n, goal - 1, k, dp) by max(n - k, 0).


class Solution {
public:
   long long MOD = 1e9+7;

   long long solve(int n , int goal , int &k , vector<vector<int>> &dp)
   {


       if(goal == 0 && n==0) return 1;
       if(goal == 0 || n ==0) return 0;
        
        if(dp[n][goal] != -1) return dp[n][goal];
          long long res =0 ;

    //    select a new unique song

         long long pick =  solve(n-1 ,goal-1 , k , dp) * n;

        //  seleting a repeated song
        // n - k = no. of different songs played till now - k
        long long not_pick = solve(n , goal-1 ,  k , dp)* max(n-k , 0);

        return dp[n][goal] = (pick + not_pick)%MOD;
        
        
   }
    int numMusicPlaylists(int n, int goal, int k) {
        
        vector<vector<int>> dp(n+1 , vector<int> (goal+1, -1));

        return solve(n, goal , k , dp);
    }
};