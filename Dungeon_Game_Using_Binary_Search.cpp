// Problem Link: https://leetcode.com/problems/dungeon-game/

// INTUITION: SO here the question says that princess is present at bottom right corner of matrix.
// And at each cell a monster may or may not be present. A cell with negative number represents a monster
// which decreases the strength of prince who has an inital strength of 's', if prince enters the cell with a monster
// then his strength will decrease by dungeon[i][j]. And if at any instance his strength becomes less than 0. He will die
// and will not be able to take that particular path further. SO we have to tell the minimum initial strength the price should have 
// inorder to reach the princess.

// Here we have used the conept of binary search and assumed that inital strength to be S, and if it is possible to rescue
// the princess, with this strength, then this can be our answer but we will try to look for a lesser strength with which he can reach.

// For every new strength we are calling a dfs, whose task is just to store the maximum path sum, from top-left to bottom right corner.
// So this question is just a variant of maximum path sum, with only differnce in base case.

// For the base case when we reach the top-left corner, we will check if the strengh of prince will increase or decrease to become less than 0.
// If stregth at the starting cell becomes less than 0, then will return a very small value of INT_MIN, saying it is not possible.

// SO if from both the direction i am getting less than 0 strength, it will mean that it is not possible, to reach princess with this path.
// So try other paths.



class Solution {
public:
    int n,m;
    int dp[201][201];
    int dfs(int r, int c, vector<vector<int>>& dungeon, int strength)
    {
        if(r < 0 || r >= n || c < 0 || c >= m ) return -1e7;

        if(r == 0 && c == 0) return strength + dungeon[0][0] > 0 ? strength + dungeon[0][0] : -1e7 ;
        
        if(dp[r][c] != -1) return dp[r][c];
        int up = dungeon[r][c] + dfs(r-1, c, dungeon, strength);
       
        
        int lft = dungeon[r][c] + dfs(r, c-1, dungeon, strength);
        
        if(lft <= 0  && up <=0 ) return dp[r][c] = -1e7;

        return dp[r][c] = max(lft , up);


    }
    bool isPossible(vector<vector<int>>& dungeon, int &strength)
    {
         memset(dp, -1, sizeof dp);

         return dfs(n-1,m-1, dungeon, strength ) >  0 ;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
           n = dungeon.size();
           m = dungeon[0].size();
           
           int lo = 1, high = 1e6;
            int ans= 0;
        while(lo <= high)
        {
            int s = (lo + high)/2;
           

            if(isPossible(dungeon, s))
            {
                ans = s;
               
                high = s-1;
            } 
           else
            { lo = s+1;
            
            }
             
        }
        
        return ans;

    }
};