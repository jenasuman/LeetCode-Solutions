// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    long long int dp[4][3][26];
    long long int f(int r,int c,int N,vector<vector<int>>& keyPad){
        
        
        if(r>3 || r<0 || c>2 || c<0 || keyPad[r][c]==-1)return 0;
        if(N==0)return 1;
        if(dp[r][c][N]!=-1)return dp[r][c][N];
        long long int c1=f(r-1,c,N-1,keyPad);
        long long int c2=f(r+1,c,N-1,keyPad);
        long long int c3=f(r,c-1,N-1,keyPad);
        long long int c4=f(r,c+1,N-1,keyPad);
        long long int c5=f(r,c,N-1,keyPad);
        
        return dp[r][c][N]=c1+c2+c3+c4+c5;
        
        }

	public:
	long long getCount(int N)
	{
		// Your code goes here
		   
		   vector<vector<int>> v(4,vector<int>(3,-1));
		   
		   
		   v[0][0]=1;
		   v[0][1]=2;
		   v[0][2]=3;
		   
		   v[1][0]=4;
		   v[1][1]=5;
		   v[1][2]=6;
		   
		   v[2][0]=6;
		   v[2][1]=8;
		   v[2][2]=9;
		   
		   v[3][1]=0;
		   long long int ans=0;
		   memset(dp,-1,sizeof(dp));
		   for(int i=0;i<4;i++){
		       
		       for(int j=0;j<3;j++){
		           
		           if(v[i][j]!=-1){
		               ans=(ans+f(i,j,N-1,v));
		           }
		           
		           
		       }
		       
		       
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

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends