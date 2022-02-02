class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};
    void solve(int x,int y,vector<vector<int>>& grid){
        
        int n=grid.size();
        int m=grid[0].size();
        
        grid[x][y]=0;
        
        for(int i=0;i<4;i++){
            
            int currX=x+dx[i];
            int currY=y+dy[i];
            
            if(currX>=0 && currY>=0 && currY<m && currX<n && grid[currX][currY]==1){
                solve(currX,currY,grid);
            }
            
            
            
        }
        
        
        
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1)
                    solve(i,j,grid);
                }
                
                
            }
        }
        int count=0;
         for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               
                if(grid[i][j]==1)count++;
                
                
            }
        }
        return count;
        
    }
};