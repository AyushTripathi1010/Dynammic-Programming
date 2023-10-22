// Problem Link: https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

// INTUITION: Here the constraints are pretty large so that is why recursion + memoization technique does not work
// So we can solve this question using tabulation method, and using an additional array for storing the maximum sum of subsequence 
// acheived till the ith index.
// For every iteration of i we are looping j backwards to check what all elements can be part of and what is the maximum sum they can 
// provide, provided that previous elements should be smaller than the current ith element.

// Just consider eg: [100, 1,2,105].
// here the vector v which stores the maximum LIS sum till ith index:
// v= [100, 1, 3, 205].

class Solution{
		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    vector<int> v(arr , arr+n);
	    v[0] = arr[0];
	    int res = v[0];
	    for(int i = 1 ; i < n ; i++)
	    {
	        for(int j = i-1; j>=0  ; j--)
	        {
	            if(arr[j] < arr[i]) 
	            {v[i] = max(v[i] , arr[i] + v[j]);
	             
	            }
	            
	        }
	        res = max(res, v[i]);
	    }
	    
	    return res;
	}  
};