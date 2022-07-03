class Solution {
public:
    using ll=long long int;
    int mod=1e9+7;
    int n;
    int m;
    ll f(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dp){
        
        if(dp[r][c]!=-1)return dp[r][c];
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        ll ans=1;
        for(int i=0;i<4;i++){
            
            int x=r+dx[i];
            int y=c+dy[i];
            
            if(x<n && y<m && x>=0 && y>=0 && grid[r][c]<grid[x][y]){
                ans=(ans+f(x,y,grid,dp))%mod;
            }
            
            
            
        }
        
        return dp[r][c]=ans;
        
        
        
    }
    int countPaths(vector<vector<int>>& grid) {
          
           n=grid.size();
          m=grid[0].size();
          vector<vector<int>> dp(n,vector<int>(m,-1));
          ll ans=0;
          for(int i=0;i<n;i++){
              for(int j=0;j<m;j++){
                  
                  
                  ans=(ans+f(i,j,grid,dp))%mod;
                  
                  
                  
              }
          }
       return ans;
    }
};