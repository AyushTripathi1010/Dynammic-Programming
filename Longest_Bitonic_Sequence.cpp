// Coding Ninja Link: https://www.codingninjas.com/studio/problems/longest-bitonic-sequence_1062688?leftPanelTab=1

// INTUITION: What does Bitonic mean?
// Bitonic sequence is a sequence which is first strictly increasing and then strictly
// decreasing. A bitonic sequence can even be strictly increasing only or strictly
// decreasing only.

// So our approcach is to find the LIS , and store it in dp table, and then
// to get the Longest decreasing subsequence we will do backward LIS.
// and then corresponingly check the maxium summation of dp1[i]+dp2[i] -1.
// 1 is subtracted to avoid the peak value to be repeated twice.

int longestBitonicSubsequence(vector<int>& arr, int n)
{
	
	//  Step 1: first find LIS
	 vector<int> dp1(n , 1);
	 for(int i= 0 ; i < n ; i++)
	 {
		 for(int prev_idx = 0 ; prev_idx < i ; prev_idx++)
		 {
			 if(arr[i] > arr[prev_idx] && 1+dp1[prev_idx] > dp1[i])
			 {
				 dp1[i] = 1 + dp1[prev_idx];
			 }
		 }
	 }
       
	   vector<int>dp2(n , 1);
	 for(int i= n-1 ; i>=0 ; i--)
	 {
		 for(int prev_idx = n-1 ; prev_idx > i ; prev_idx--)
		 {
			 if(arr[i] > arr[prev_idx] && 1+dp2[prev_idx] > dp2[i])
			 {
				 dp2[i] = 1 + dp2[prev_idx];
			 }
		 }
	 }
       int ans = 1;
	 for(int i =0 ; i < n ; i++)
	 {
		 ans = max(ans , dp1[i] + dp2[i]-1);
	 }

	 return ans;
}
