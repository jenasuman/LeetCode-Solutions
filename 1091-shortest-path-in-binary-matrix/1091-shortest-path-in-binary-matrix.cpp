class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
               int dx[8]={0,0,-1,1,1,-1,1,-1};
        int dy[8]={-1,1,0,0,1,-1,-1,1};
        
        queue<pair<int,pair<int,int>>> q;
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        
        
        q.push({1,{0,0}});
        
        grid[0][0]=1;
        while(!q.empty()){
            
            auto curr=q.front().second;
    
            int currX=curr.first;
            int currY=curr.second;
            // grid[currX][currY]=1;
            int dis=q.front().first;
            if(currX==n-1 && currY==m-1)return dis;
            q.pop();
            // cout<<currX<<" "<<currY<<" "<<dis<<"\n";
            for(int i=0;i<8;i++){
                int x=currX+dx[i];
                int y=currY+dy[i];
            
                if(x>=0 && x<n && y>=0 && y<m && grid[x][y]!=1)
                {   
                    // if(x==n-1 && y==m-1)return dis+1;
                    q.push({dis+1,{x,y}});
                    grid[x][y]=1;
                }
                
                
            }
            
            
            
            
            
        }
        return -1;
    }
};