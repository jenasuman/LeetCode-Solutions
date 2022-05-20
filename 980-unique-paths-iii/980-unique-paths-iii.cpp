class Solution {
public:
    int n,m;
    int dx[4]={0,0,-1,1};
    int dy[4]={-1,1,0,0};
    int solve(int x,int y,int targetX,int targetY,int count,vector<vector<int>>& grid){
        
        if(x==targetX && y==targetY){
            // cout<<count<<" ";
            if(count==-1){
                return 1;
            }
            else return 0;
        }
    
        
        int ans=0;
        
        for(int i=0;i<4;i++){
            
            int currX=x+dx[i];
            int currY=y+dy[i];
            
            if(currX>=0 && currY>=0 && currX<n && currY<m && grid[currX][currY]!=-1){
                
                grid[currX][currY]=-1;
                ans+=solve(currX,currY,targetX,targetY,count-1,grid);  
                grid[currX][currY]=0;
                
            }
            
            
        }
        
        
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        
         n=grid.size();
         m=grid[0].size();
        
        int targetX,targetY,startX,startY;
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    startX=i;
                    startY=j;
                }
                if(grid[i][j]==2){
                    targetX=i;
                    targetY=j;
                }
                if(grid[i][j]==0)count++;
            }
        }
        // cout<<count;
        grid[startX][startY]=-1;
        return solve(startX,startY,targetX,targetY,count,grid);
        
        
        
    }
};