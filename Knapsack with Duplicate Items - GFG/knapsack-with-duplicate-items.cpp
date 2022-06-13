// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int f(int index,int val[],int wt[],int W,int dp[][1001]){
        
        if(index<0)return 0;
        if(dp[index][W]!=-1)return dp[index][W];
        int pick=(W>=wt[index])?val[index]+f(index,val,wt,W-wt[index],dp):0;
        int notPick=f(index-1,val,wt,W,dp);
        
        return dp[index][W]=max(pick,notPick);
        
        
        
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {   
        if(N==0)return 0;
        int dp[1001][1001];
        memset(dp,-1,sizeof(dp));
        return f(N-1,val,wt,W,dp);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends