class Solution {
public:
    // using pair<int,pair<int,int>> p;
    int minimumEffortPath(vector<vector<int>>& heights) {
        
          priority_queue <pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
          
          int ans;
        
          pq.push({0,{0,0}});
        
          int n=heights.size();
          int m=heights[0].size();
        
          vector<vector<int>> vis(n,vector<int>(m,-1));
          int dx[4]={0,0,-1,1};
          int dy[4]={-1,1,0,0};
          while(!pq.empty()){
              
              auto d=pq.top().first;
              auto p=pq.top().second;
              auto x=p.first;
              auto y=p.second;
              pq.pop();
              if(x==n-1 && y==m-1)return d;
              
              if(vis[x][y]!=-1)continue;
              
              vis[x][y]=d;
              
              
              
              for(int i=0;i<4;i++){
                  
                  int currX=x+dx[i];
                  int currY=y+dy[i];
                  
          if(currX<n && currX>=0 && currY<m && currY>=0){
                 int z=abs(heights[x][y]-heights[currX][currY]);
              
                 z=max(z,d);
                 
                 pq.push({z,{currX,currY}});
                
          }
                  
                  
                  
                  
              }
              
              
              
              
              
          }
        
        return vis[n-1][m-1];
    }
};