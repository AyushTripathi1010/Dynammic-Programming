// Problem Link: https://www.codingninjas.com/studio/problems/problem-name-boolean-evaluation_1214650?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0

// INTUITION : here we have to try to partition the expression at every operand
// we can compare it to rod cutting problem where we partioned the left part
// and right part.
// In this problem also at every operand we will partition the expression
// in to left and right sub expression and solve, them, here every operand
// will be at a distance of i+2, from the previous operand.
// here we have to carr the 3rd state of isTrue, because and expression can 
// give me either true or false. and if i want, suppose left expression to
// give true then i will pass 1 , if want left expression can give me false
// then pass 0. 
// i am ccalculating for both true and false , because an expression can 
// result in giving true , with the combnation of true and false also,
// so it is importnt to keep track of true and false both.

// Eg : exp1 | exp2 , and 
// lT of exp1 = 3 , lF of exp1 = 1
// rT of exp1 = 1 , rF of exp1 = 2
// ways = ways + (3*2) + (3*1) + (1*1) = 10 ways to get true, when partioned
//  from 'or' operand. Similarly other operands will also give ways.
#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9+7;
int dp[201][201][2];
long long solve(int i , int j , int isTrue , string &exp)
{
    if(i> j) return 0;

    if(i == j)
    {
        if(isTrue)
        return exp[i] == 'T';

        else return exp[i] == 'F';
    }
     if(dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

      long long ways =0 ;
    for(int idx = i+1 ; idx<= j-1 ; idx+=2 )
    {
        long long lT = solve(i , idx-1 , 1 , exp);
        long long lF = solve(i , idx-1 , 0 , exp);
        long long rT = solve(idx+1 , j , 1 , exp);
        long long rF = solve(idx+1 , j , 0 , exp);

        if(exp[idx] == '&')
        {
            if(isTrue)
            {
                ways = (ways%MOD + (lT*rT)%MOD)%MOD;
            }
            else 
            {
                ways = (ways%MOD + (lT*rF)%MOD + (lF*rF)%MOD + (lF*rT)%MOD)%MOD;
            }
        }
        else if(exp[idx] == '|')
        {
            if(isTrue)
            {
                ways = (ways%MOD + (lT*rF)%MOD + (lT*rT)%MOD + (lF*rT)%MOD)%MOD;
            }
            else
            {
                ways = (ways%MOD + (lF*rF)%MOD)%MOD;
            }
        }
        else
        {
            if(isTrue)
            {
                ways = (ways%MOD + (lT*rF)%MOD  + (lF*rT)%MOD)%MOD;
            }
            else
            {
                ways = (ways%MOD + (lF*rF)%MOD + (lT*rT)%MOD)%MOD;
            }
        }

    }
     return  dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) {
    
     int n = exp.size();
     
     memset(dp , -1, sizeof dp);
     return (int)solve(0 , n-1 , 1 , exp);
}