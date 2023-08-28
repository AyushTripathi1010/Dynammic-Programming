// Coding Ninja Link: https://www.codingninjas.com/studio/problems/number-of-longest-increasing-subsequence_3751627?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0


// INTUITION : here we have to find the number of longest increasing sequences.
// eg: [1,5,4,3,2,6,7, 10, 8, 9]
// dp: [1,2,2,2,2,3,4, 5, 5, 6]
// cnt:[1,1,1,1,1,4,4, 4, 4, 4]

// How is the count array working ?
// for every index of array we are looking for how many subsequence of length dp[i]
//  are ending with arr[i].
// eg: for element  = 6 at index = 5, the dp[5] = 3, that means longest length till
// this index is 3. so the cnt array will count all the subsequences of length 3
// that are ending with 6.
// so here : LIS of value 6 is 3 with count 4 {(1,5,6),(1,4,6),(1,3,6),(1,2,6)}.

// so whenever we are getting a new increased dp length we are storing the count of that element
// from which index it is getting that increment.
#include<bits/stdc++.h>
int findNumberOfLIS(vector<int> &arr)
{
    int n = arr.size();


    vector<int> dp(n , 1);
    vector<int> count(n ,1);
    int maxi = 1;
    for(int i = 0 ;i< n ; i++)
    {
        for(int prev_idx = 0 ; prev_idx < i ; prev_idx++)
        {
            if(arr[i] > arr[prev_idx] && 1+dp[prev_idx] > dp[i])
            {
                dp[i] = 1 + dp[prev_idx];
                count[i] = count[prev_idx];
            }
            else if(arr[i] > arr[prev_idx] && 1+dp[prev_idx] == dp[i])
            {
                count[i]+= count[prev_idx];
            }

        }

        maxi = max(maxi , dp[i]);
    }
      
      // counting all the lis with maximum length.
     int ans= 0 ;
    for(int i =0; i< n ; i++)
    {
        if(maxi == dp[i]) ans+= count[i];
    }

    return ans;
}