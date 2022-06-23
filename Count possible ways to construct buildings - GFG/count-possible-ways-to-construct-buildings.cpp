// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int mod=1e9+7;
    long long int dp[100001][2];
    long long int f(int i,int prev,int N){
        
        if(i>N){
            return 1;
        }
         long long int case1=0;
         long long int case2=0;
         if(dp[i][prev]!=-1)return dp[i][prev];
         if(prev==0){
             
             case1=f(i+1,1,N);
             case2=f(i+1,prev,N);
             
             
         }
          
          if(prev==1){
              
              case1=f(i+1,0,N);
              
          }
        
        return dp[i][prev]=(case1+case2)%mod;
        
    } 
	public:
	int TotalWays(int N)
	{
       
       vector<vector<long long int>> d(N+2,vector<long long int>(2,0));
       
       d[N+1][0]=1;
       d[N+1][1]=1;

       for(int i=N;i>=1;i--){
           
           for(int j=0;j<2;j++){
               
               if(j==0){
                   d[i][j]=(d[i+1][1]+d[i+1][0])%mod;
               }
               else{
                   d[i][j]=d[i+1][0];
               }
               
               
           }
           
           
           
       }
    //   for(int i=1;i<=(N+1);i++){
    //       for(int j=0;j<2;j++){
    //           cout<<d[i][j]<<" ";
    //       }
    //       cout<<"\n";
    //   }
       long long int ans=d[1][0];
       return (ans*ans)%mod;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends