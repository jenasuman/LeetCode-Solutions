// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  long long int f(int h,int dp[]){
      
    if(h<=1)return 1;
    int mod=1e9+7;
    
    if(dp[h]!=-1)return dp[h]%mod;
    return dp[h]=(f(h-1,dp)*(f(h-1,dp)+f(h-2,dp)*2))%mod;
     
     
      
  }    
  public:
    long long int countBT(int h) { 
       

        int mod=1e9+7;
        
        int dp[1001];
        memset(dp,-1,sizeof(dp));    
        return f(h,dp)%mod;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}
  // } Driver Code Ends