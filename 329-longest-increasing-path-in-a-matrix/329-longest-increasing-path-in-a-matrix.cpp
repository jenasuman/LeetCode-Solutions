class Solution {
public:
  
    int solve(int x,int y,int n,int m,vector<vector<int>>& mat,vector<vector<int>>& dp,int prev){
        
        if(x<0 || y<0 || x>=n || y>=m || mat[x][y]<=prev)return 0;
        
        if(dp[x][y]!=-1)return dp[x][y];
        
        int l=solve(x,y-1,n,m,mat,dp,mat[x][y]);
        int r=solve(x,y+1,n,m,mat,dp,mat[x][y]);
        int u=solve(x-1,y,n,m,mat,dp,mat[x][y]);
        int d=solve(x+1,y,n,m,mat,dp,mat[x][y]);

        
        return dp[x][y]=max({l,r,d,u})+1;
        
        
        
    }
    
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=1;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
        
        for(int j=0;j<m;j++){
             int temp=solve(i,j,n,m,matrix,dp,-1);   
            ans=max(temp,ans);
        }
        }
        return ans;
    }
};