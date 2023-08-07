// GFG LINK: https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string-1587115620/1
class Solution{
    public:
    //Complete this function
    int n;
    //  INTUITION : To generate all permutations, just swap each element with itself
    //  and with the element to it's right
    // and do this recusrively for every index.
    void solve(int idx , string S , vector<string>&ans)
    {
        
        if(idx == n)
        {
            ans.push_back(S);
            return;
            
        }
        
        for(int i = idx ; i< n ; i++)
        {
            swap(S[i], S[idx]);
            
            solve(idx+1 , S , ans);
            
            // undoiing the swap. i.e backtracking
            swap(S[i] ,S[idx]);
            
        }
        
        
        
    }
    
    vector<string> permutation(string S)
    {
        //Your code here
        
         n = S.size();
       
        vector<string> ans;
        
        solve(0 , S , ans);
        
        // The output is in sorted manner, so that is why we are sorting it.
        sort(ans.begin() , ans.end());
        
        return ans;
        
        
    }
};