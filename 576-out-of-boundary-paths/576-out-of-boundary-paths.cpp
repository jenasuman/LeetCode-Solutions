class Solution {
public:
    int mod=1e9+7;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    using ll=long long int;
    ll dp[52][52][52];

    int f(int i,int j,int maxMoves,int n,int m){
        
        if(i>=n || j>=m || i<0 || j<0)return 1;  
        
        if(maxMoves==0)return 0;
        
        if(dp[i][j][maxMoves]!=-1)return dp[i][j][maxMoves];
        
        ll ans=0;
        
        for(int k=0;k<4;k++){
            
            int x=i+dx[k];
            int y=j+dy[k];
            
            ans=(ans+f(x,y,maxMoves-1,n,m)%mod)%mod;
            
            
            
        }
        
        return dp[i][j][maxMoves]=ans;
        
    }
    int findPaths(int m, int n, int maxMove, int r, int c) {
        
        memset(dp,-1,sizeof(dp));
        ll ans=0;
        if(maxMove==0)return 0;
        for(int i=1;i<=maxMove;i++){
            
            f(r,c,i,m,n);
            
        }
        // cout<<dp[r][c][2]<<"\n";
        return (dp[r][c][maxMove]%mod);
        
    }
};