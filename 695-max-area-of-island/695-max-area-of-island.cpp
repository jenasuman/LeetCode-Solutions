class Solution {
public:
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};
    
    void solve(int x,int y,vector<vector<int>>& grid,int& count){
    int n=grid.size();
    int m=grid[0].size();
    grid[x][y]=0;    
    count++;
    for(int i=0;i<4;i++){
        int currX=x+dx[i];
        int currY=y+dy[i];
        
        if(currX>=0 && currY>=0 && currX<n && currY<m && grid[currX][currY]==1){
            solve(currX,currY,grid,count);
        }
        
    }    
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
        
    int ans=0;
        
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            
            
            if(grid[i][j]==1){
                
                int count=0;
                
                solve(i,j,grid,count);
                
                ans=max(ans,count);
                
                
            }
            
            
            
        }
    }    
        
        
        return ans;
        
        
    }
};