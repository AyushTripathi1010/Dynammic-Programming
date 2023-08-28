// LeetCode Link: https://leetcode.com/problems/longest-string-chain/

// INTUITION: SO we are asked to find the longest string chain, which means 
// wordA is a predecessor of wordB if and only if we can insert exactly one 
// letter anywhere in wordA without changing the order of the other characters 
// to make it equal to wordB.

// Here the key point to note is that we can start in any order and from any index
// and select any index.

// But to get the longest we will have to sort the string array.
// eg: ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// if we don't sort then we will get : xbc , cxbc ,pcxbc = 3, which is wrong.

// Now if we sort : ["xb", "xbc","cxbc","pcxbc", "pcxbcf"]
// now we get xb, xbc, cxbc, pcxbc, pcxbcf = 5 , whiich is correct.

// The question is a variation of lis problem, here we just have to change the
// if condition form : if(arr[i] > arr[prev_idx] && 1+ dp[prev_idx] > dp[i]) 
// to if(checkPossible(arr[i] , arr[prev_idx]) && 1+ dp[prev_idx] > dp[i])



class Solution {
public:

        
     bool checkPossible(string &s1 , string &s2)
     {
          if(s1.size() != s2.size()+1) return false;

          int i = 0, j =0 ;

          while(i < s1.size())
          {
              if(j < s2.size() && s1[i] == s2[j])
              {
                  i++ , j++;
              }
              else
              {
                  i++;
              }
          }

          return (i == s1.size() && j == s2.size());
     }
    int longestStrChain(vector<string>& words) {
             
             int n = words.size();

            //   comparator operator or Lamda expression
              auto lamda = [&](string &w1 , string &w2)
              {
                return  w1.size() < w2.size();

              };

             sort(words.begin() , words.end() , lamda);


              
             sort(words.begin() , words.end() , comp);

             vector<int> dp(n , 1);
              int maxi = 1;
             for(int  i =0 ; i < n; i++)
             {
                 for(int prev_idx =0 ; prev_idx  < i ; prev_idx++)
                 {
                     if(checkPossible(words[i] , words[prev_idx]) && 1 + dp[prev_idx] > dp[i])
                     {
                         dp[i] = 1 + dp[prev_idx];
                         
                     }
                 }
                 maxi = max(maxi , dp[i]);
             }

             return maxi;
    }
};