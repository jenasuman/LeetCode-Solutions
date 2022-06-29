// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    int dp[100001];
    int f(int index,int A[],int N){
        
        if(index>=N-1){
            return 1;
        }
        if(A[index]==0){
            return 0;
        }
        if(dp[index]!=-1)return dp[index];
        bool ans=false;
        for(int j=1;j<=A[index];j++){
            ans=ans|f(j+index,A,N);
        }
        
        return dp[index]=ans;
        
    }
  public:
    int canReach(int A[], int N) {
        // code here
        // memset(dp,-1,sizeof(dp));
        // return f(0,A,N);
        
        int maxJump=0;
        
        for(int i=0;i<N;i++){
            
            if(i>maxJump)return 0;
            
            maxJump=max(maxJump,i+A[i]);
            
        }
        
        
        return 1;
        
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.canReach(A,N) << endl;
    }
    return 0;
}  // } Driver Code Ends