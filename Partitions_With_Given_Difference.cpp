// Coding Ninjas Link : https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos


// INTUITION : The approach is dervied from the formula
// that S1 - S2 = D , also S2 = TotalSum - S1.
// S1 = D + S2   => S1 = D + (TotalSum - S1) => 2S1 = D+ TotalSum
// S1 = (D + TotalSum)/2;
// Now the question boils down to find the number of ways to 
// acheive the target S1.

#include <bits/stdc++.h> 
const int MOD = 1e9+7;
int solve(int i , int target , vector<int> &arr , vector<vector<int>> &dp)
{
    

    if(i ==0)
    {    
    	// This conditions comes into picture only when
    	// array can  have 0 values also.
        if(target == 0 && arr[0] == 0) return 2; // eg subset: 0,1,2,3 , target = 6
        // so my target will become 0 at index 1 only, that is one way but at 0 index
        // there is a 0 also which will also contribute to number of ways.
        // and can be made as an independent set.

        // this means either the target is already 0 or by including the 0th index
        // element the target will become 0 , will contribute to 1 way.
        if(target == 0 || arr[0] == target) return 1;
        
        //  other wise contribute 0 way.
        return 0;
    }
    if(dp[i][target] != -1) return dp[i][target];

    int pick = 0;
    if(arr[i]  <= target) pick = solve(i-1 , target- arr[i] , arr , dp);

    int not_pick = solve(i-1 , target , arr ,dp);
    
    return dp[i][target] = (pick + not_pick)%MOD;
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    
    int totsum = 0;
    for(int i= 0 ; i < n ; i++)
    {
        totsum+= arr[i];
    }
     

     if((totsum+ d)%2 || totsum+d < 0) return 0;

    int target = (totsum + d)/2; // totsum+d should be divisible by 2 to get the target.
     
    vector<vector<int>> dp(n+1 , vector<int>(target+1 , -1));

    return solve(n-1 , target , arr , dp);
}


