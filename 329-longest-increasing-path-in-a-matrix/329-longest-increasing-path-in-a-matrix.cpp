class Solution {
public:

    int dp[201][201];
    int solve(int x,int y,vector<vector<int>>& matrix, int prev){
        
    if(x<0 || y<0 || y>=matrix[0].size() || x>=matrix.size() || matrix[x][y]<=prev)
        return 0;
        
        if(dp[x][y])return dp[x][y];
        
        int l=solve(x-1,y,matrix,matrix[x][y]);
        int r=solve(x+1,y,matrix,matrix[x][y]);
        int u=solve(x,y-1,matrix,matrix[x][y]);
        int d=solve(x,y+1,matrix,matrix[x][y]);
        
        return dp[x][y]=max({l,r,u,d})+1;
        
        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        memset(dp,0,sizeof(dp));
        int ans=0;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                int x=solve(i,j,matrix,-1);
                ans=max(x,ans);
                
                
            }
            
            
            
        }
        return ans;
        
    }
};