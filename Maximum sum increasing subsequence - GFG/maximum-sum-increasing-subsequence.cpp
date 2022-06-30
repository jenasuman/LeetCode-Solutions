// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int dp[1002][1002];
    int f(int i,int prev,int n,int arr[]){
        
        
        if(i>=n)return 0;
        
        int choice1=0;
        int choice2=0;
        if(dp[i][prev]!=-1)return dp[i][prev];
        if(prev==0 || arr[i]>arr[prev-1]){
            choice1=arr[i]+f(i+1,i+1,n,arr);
        }
        
        choice2=f(i+1,prev,n,arr);
        
        return dp[i][prev]=max(choice1,choice2);
        
    }		

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    
	   // int prev=-1;
	   // memset(dp,-1,sizeof(dp));
	   //return f(0,0,n,arr);
	   vector<int> dp(n,0);
	   dp[0]=arr[0]; 
	   int ans=dp[0];
	   for(int i=1;i<n;i++){
	       
	       
	       for(int j=0;j<i;j++){
	           int choice1=0;
	           int  choice2=0;
	           if(arr[i]>arr[j]){
	               //cout<<arr[i]<<" "<<arr[j]<<"\n";
	               choice1=arr[i]+dp[j];
	               //cout<<choice1<<"\n";
	               
	           }
	           choice2=arr[i];
	           //cout<<choice1<<" "<<choice2<<"\n";
	           dp[i]=max({dp[i],choice1,choice2});
	           
	           
	       }
	       
	       
	       
	       //cout<<dp[i]<<"\n";
	       ans=max(dp[i],ans);
	       
	   } 
	   
	    return ans;
	    
	}  
};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}

  // } Driver Code Ends