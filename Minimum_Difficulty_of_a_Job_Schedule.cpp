// Problem Link : https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/


// INTUITION : So we are given an array name jobDifficulty , where jobDifficulty[i]
// represents the diffculty of the ith job , and also given an integer days, 
// which tells us to finish all the tasks in exacly d days.
// So what we have to do is partition the array into d cuts, and in each partition
// we need to check maximum difficulty from a given partition, and similary maximum's
// from other partitions as well, and add them .

// The catch is that, taking differnt length partitions result in different maximums
// for that paritions, and on summing up all the maxi's of the partitions.
// we need the minimum sum.
class Solution {
public:
    int N;
    int dp[301][11];
    int solve(int idx , int days , vector<int> &JobD)
    {
        if(idx < N && days ==0 ) return 1e8;  // if days has become 0 and more than d paritions are going to happen
        if( idx ==N && days ==0) return 0; // if exactly d partitions have happened then yes, return 0.

        if(dp[idx][days] != -1) return dp[idx][days];
        
        int maxi = 0;
        int ans= 1e8 ;
        for(int i  = idx ; i < N ; i++)
        {
            maxi = max(maxi , JobD[i]);
            
            int res = maxi +  solve(i+1 , days-1 , JobD);

            ans = min(ans ,res);
            

        }

        return dp[idx][days] = ans;

    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
          
          N = jobDifficulty.size();
          if(d > N) return -1;
          memset(dp , -1 , sizeof dp);
          return solve(0 , d , jobDifficulty);
    }
};