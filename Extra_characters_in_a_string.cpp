// Leetcode Link: https://leetcode.com/problems/extra-characters-in-a-string/


// INTUITION : our task is to   break string s into one or more non-overlapping substrings
 // such that each substring is present in dictionary. There may be some extra characters in 
// s which are not present in any of the substrings.


//  TestCase example : s = "leetscode", dictionary = ["leet","code","leetcode"]

// here we will have to break string s into each character, and check it's
// existence in the dictionary

// the recursion will first break it like this: 'l' , solve('eetscode')
// and check if 'l is present in set or not, if yes, it means 0 extra characters'
// other wise 1 extra character.
// then it will futher break, 'e' , solve(;'etscode').

// while backtracking , the initial call will then become: 'le', (etscode),
// finally , it will come to a point like this: 'leet', solve('scode'),
// and this time leet is present so 0 extra chacters will be there.
// and so on we will get our result.

// for any confusion just do a dry run.
class Solution {
public:
    unordered_set<string> st;
    int N;
    int solve(int idx , string &s , vector<int> &dp)
    {
        if(idx >= N) return 0;

        if(dp[idx] != -1) return dp[idx];

        string curr_substring = "";
        int min_operations = INT_MAX;
        for(int i = idx ; i < N ; i++)
        {   
            curr_substring.push_back(s[i]);

            int curr_extras = st.find(curr_substring) == st.end() ? curr_substring.size() : 0;
        
            int remainExtras = solve(i+1 , s, dp);

            int result = curr_extras+ remainExtras;

            min_operations = min(min_operations , result);

        }
        return dp[idx] = min_operations;

    }
    int minExtraChar(string s, vector<string>& dictionary) {
            
             N = s.size();
            int d = dictionary.size();
             
            for(string &str : dictionary)
            {
                st.insert(str);
            }
            vector<int> dp(N+1 , -1);
            return solve(0 , s, dp);
            
    }
};