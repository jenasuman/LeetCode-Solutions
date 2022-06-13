class Solution {
public:
    int m,n;
    int dp[51][51];
    int sol(vector<vector<int>>& grid, vector<vector<int>>& moveCost,int i,int j){
        if(i == m-1)
            return grid[i][j];
        if(j==n)
            return INT_MAX;
         int ans = INT_MAX;
        if(dp[i][j]!=-1)return dp[i][j];
        for(int k=0;k<n;++k){
            int current = grid[i][j] + moveCost[grid[i][j]][k];
            if(dp[i+1][k]==-1){
                dp[i+1][k]=sol(grid,moveCost,i+1,k);
            }
            current+=dp[i+1][k];
            ans = min(ans,current);
           
        }
        return dp[i][j]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
         m = grid.size();
         n=grid[0].size();
         int ans=INT_MAX; 
        memset(dp,-1,sizeof(dp)); 
         for(int i=0;i<n;i++){
            
            ans=min(ans,sol(grid,moveCost,0,i));
         }
       
        return ans;
    }
};