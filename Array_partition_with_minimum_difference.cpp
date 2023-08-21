// Coding Ninjas Link : https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos 


// INTUITION: This is an important problem related to subset
// sum equals target, here we have to partition the array
// into 2 subsets such that the absolute difference of S1
// and subset S2 is minimum.

// In the problem we will have to check for which all targets
// in the range of (0 to summation of all values) we can 
// partition the subset, and for each possible target we will
// find the absolute difference of S1-S2.

// Here The Tabulation Table is important because it stores,
// till every index what all possible targets are possible.
// so in the dp table we are only concerned with the last
// row as it stores,  which all targets are possible.

// First step is do the normal subset sum equals to target
// here target will be summation of all values, because that 
// can be the maximum target value possible.


#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
     
     int totalSum = 0;
	 for(int i =0 ; i < n ; i++)
	 {
		 totalSum+= arr[i];
	 }



	vector<vector<bool>> dp( n+1 , vector<bool> (totalSum+1 , 0));

    for(int i =0 ; i < n ; i++) dp[i][0] = true;
     if(arr[0] <= totalSum) dp[0][arr[0]] = true;

    for(int i =1 ; i<  n ; i++)
    {
        for(int target = 1; target <= totalSum/2 ; target++)
        {
            int not_pick = dp[i-1][target];
            
            
            int pick = false;
            if(target >= arr[i])
            pick = dp[i-1][target-arr[i]];
            
            
            dp[i][target] = (not_pick | pick);
        }
    }

    //  Now iterating the last row of dp table and 
    // trying to find the minimum absolute difference.
	int mini = INT_MAX;
	for(int i =0 ; i <= totalSum/2 ; i++)
	{
		if(dp[n-1][i]== true)
		{
			int s1 = i;
			int s2 = totalSum - i;
			mini = min(mini , abs(s2-s1));
		}
	}

    return mini;
}
