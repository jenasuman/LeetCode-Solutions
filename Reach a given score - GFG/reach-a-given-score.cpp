// { Driver Code Starts
// Driver Code
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

 // } Driver Code Ends
// Complete this function

long long int f(long long int n,long long int i,long long int arr[]){
    
    if(n==0){
        return 1;
    }
    
    if(i<0 )return 0;
    
    long long int pick=(arr[i]<=n)?f(n-arr[i],i,arr):0;
    long long int notPick=f(n,i-1,arr);
    
    return pick+notPick;
    
}

long long int count(long long int n)
{
      long long int dp[1001];
      
      memset(dp,-1,sizeof(dp));
      
      long long int arr[3]={3,5,10};
      
      return f(n,2,arr);
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends