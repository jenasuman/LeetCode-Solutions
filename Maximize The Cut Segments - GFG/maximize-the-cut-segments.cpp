// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends


class Solution
{   int dp[10002][3];
    int mi=-(1e4+4);
    public:
    //Function to find the maximum number of cuts.
    int f(int i,int n,vector<int>& cut){
        
        if(n==0)return 0;
        
        if(i>2)return mi;
        
        
        if(dp[n][i]!=-1)return dp[n][i];
        int choice1=mi;
        int choice2=mi;
          
         if(n>=cut[i])    
         choice1=1+f(i,n-cut[i],cut);
         choice2=f(i+1,n,cut);
        
        
        return dp[n][i]=max(choice1,choice2);
        
        
    }
    
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<int> cut(3);
        cut[0]=x;
        cut[1]=y;
        cut[2]=z;
        sort(begin(cut),end(cut));
        memset(dp,-1,sizeof(dp));
        int ans=f(0,n,cut) ;
        return ans<0?0:ans;
        
        
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends