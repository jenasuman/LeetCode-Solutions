// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int mod=1e9+7;
    long long int f(int n){
        
        if(n==1)return 1;
        if(n==0)return 1;
        
        
        return f(n-1)%mod+((long long int)(n-1)*f(n-2))%mod;
        
        
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        
        long long int dp[10004];
        
        memset(dp,-1,sizeof(dp));
        
        dp[0]=1;
        dp[1]=1;
        
        for(long long int i=2;i<=n;i++){
            
            dp[i]=((dp[i-1]%mod)+((i-1)*dp[i-2])%mod)%mod;
            
        }
        
        
        return dp[n];
        
        
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends