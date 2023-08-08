// Coding Ninjas: https://www.codingninjas.com/studio/problems/ninja-s-training_3621003?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos
#include<bits/stdc++.h>

int solve(int day , int last , vector<vector<int>> &points, vector<vector<int>>&dp)
{
     // Base Case at day 0
     if(day == 0)
     { int maxi = 0;
     for(int task = 0; task < 3 ; task++)
     {
       if (task != last) {
         maxi = max(points[0][task], maxi);
       }
     }
     return maxi;
     }

     if(dp[day][last] != -1) return dp[day][last];

     
    int maxi = 0;
     for(int task = 0; task < 3 ; task++)
     {    
        // the current task should be equal to previous day task
         if(task!= last)
         {
             
             int ans = points[day][task] + solve(day-1 , task , points, dp);
              maxi = max(maxi , ans);
         }
     }
     return dp[day][last] = maxi; 
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    
    vector<vector<int>> dp(n , vector<int> (4 , -1));
    
    return solve(n-1 , 3 ,  points , dp );


    // TABULATION
    vector<vector<int>> dp(n , vector<int> (4 ,0));
       dp[0][0] =  max(points[0][1] , points[0][2]);
       dp[0][1] =  max(points[0][0] , points[0][2]);
       dp[0][2] =  max(points[0][0] , points[0][1]);
       dp[0][3] =  max(points[0][0] , max(points[0][2] , points[0][1]));
        
        
        for(int day = 1 ; day< n ; day++)
        {
            
            for(int last = 0 ; last < 4 ; last++)
            {
                 int maxi =0;
                for(int task = 0 ; task < 3 ; task++)
                {   
                    if(task!= last)
                    {
                        
                        int ans = points[day][task] + dp[day-1][task];
                        maxi = max(maxi , ans);
                    }
                }
                
                dp[day][last] = maxi;
            }
                
             
        }

        return dp[n-1][3];

        // Space Optimisation
        
        vector<int> prev(4 , 0);
       prev[0] =  max(points[0][1] , points[0][2]);
       prev[1] =  max(points[0][0] , points[0][2]);
       prev[2] =  max(points[0][0] , points[0][1]);
       prev[3] =  max(points[0][0] , max(points[0][2] , points[0][1]));
        
        
        for(int day = 1 ; day< n ; day++)
        {
            vector<int> curr(4 , 0);
            for(int last = 0 ; last < 4 ; last++)
            {
                 int maxi =0;
                for(int task = 0 ; task < 3 ; task++)
                {   
                    if(task!= last)
                    {
                        
                        int ans = points[day][task] + prev[task];
                        maxi = max(maxi , ans);
                    }
                }
                
                curr[last] = maxi;
            }
            
             prev = curr;
                
             
        }

        return prev[3];

}