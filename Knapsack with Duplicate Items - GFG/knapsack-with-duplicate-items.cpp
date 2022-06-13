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
        
        // TC: O(N*W)
        // SC: O(N*W)+O(N)
        
    }
public:
    int knapSack(int N, int W, int val[], int wt[])
    {   
        if(N==0)return 0;
        int dp[1002][1002];
        memset(dp,0,sizeof(dp));
        
        
        for(int i=1;i<=N;i++){
            
            for(int w=1;w<=W;w++){

               int pick=(w>=wt[i-1])?val[i-1]+dp[i][w-wt[i-1]]:0;
               int notPick=dp[i-1][w];  
                  
               dp[i][w]=max(pick,notPick);    
                
                
            }
            
            
            
        }
        
        return dp[N][W];
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