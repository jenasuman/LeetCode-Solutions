class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int dx[8]={0,0,-1,1,1,-1,1,-1};
        int dy[8]={-1,1,0,0,1,-1,-1,1};
        
        queue<pair<int,int>> q;

        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[0][0]==1 || grid[n-1][m-1]==1)return -1;
        
        
        q.push({0,0});
        grid[0][0]=1;
        int cnt=0;
        
        while(!q.empty()){
            cnt++;
            
            int l=q.size();
            
            for(int i=0;i<l;i++){
                
                auto p=q.front();
                q.pop();
                
                int x=p.first;
                int y=p.second;
                
                if(x==n-1 && y==m-1)return cnt;
                
                for(int j=0;j<8;j++){
                    int currX=x+dx[j];
                    int currY=y+dy[j];
                    
                    
              if(currX<n && currX>=0 && currY>=0 && currY<m && grid[currX][currY]==0){
                  grid[currX][currY]=1;
                  q.push({currX,currY});
              }
                    
                    
                }
                
                
                
            }
            
        }
        return -1;
        
    }
};