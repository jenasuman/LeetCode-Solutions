// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int n;
    int dp[505][2500];
    int f(int i,int rem,vector<int>& nums,int k){
       
      if(i==n)return 0;
      if(dp[i][rem]!=-1)return dp[i][rem];
      int choice1=1e8;
      int choice2=1e8;
      if(rem>nums[i]){
          choice1=f(i+1,rem-nums[i]-1,nums,k);
      }
      choice2=(rem*rem)+f(i+1,k-nums[i],nums,k);
      
      return dp[i][rem]=min(choice1,choice2);        
        
        
    }
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return f(1,k-nums[0],nums,k);
        
        
        
        
    } 
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}  // } Driver Code Ends