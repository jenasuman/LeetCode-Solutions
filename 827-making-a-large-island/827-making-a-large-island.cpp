class Solution {
public:
    pair<int,int> findParent(int x,int y,vector<vector<pair<int,int>>>& parent){
        
        int px=parent[x][y].first;
        int py=parent[x][y].second;
        
        if(px==x && py==y)return {x,y};
        
        return parent[x][y]=findParent(px,py,parent);
        
        
    }
    void dsu(vector<vector<pair<int,int>>>& parent,vector<vector<int>>& rank,int x,int y,int cx,int cy){
        
        auto p1=findParent(x,y,parent);
        auto p2=findParent(cx,cy,parent);
        x=p1.first;
        y=p1.second;
        cx=p2.first;
        cy=p2.second;
        // cout<<x<<" "<<y<<" "<<cx<<" "<<cy<<"\n";
        if(p1!=p2){
            
            if(rank[x][y]<rank[cx][cy]){
                swap(x,cx);
                swap(y,cy);
            }
            // cout<<"hello";
            parent[cx][cy]={x,y};
            rank[x][y]+=rank[cx][cy];
            
            
        }
        
        
        
        
        
    }
    
    using p=pair<int,int>;
    int largestIsland(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        vector<vector<p>> parent(n,(vector<p>(m)));
        vector<vector<int>> rank(n,vector<int>(m,1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                parent[i][j]={i,j};
                rank[i][j]=grid[i][j];
            }
        }
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                if(grid[i][j]==1){
                    
                    for(int k=0;k<4;k++){
                        
                        int x=i+dx[k];
                        int y=j+dy[k];
                        // cout<<x<<" "<<y<<"\n";
                        if(x>=0 && x<n && y<m && y>=0 && grid[x][y]==1)
                        dsu(parent,rank,i,j,x,y);
                      }
                  }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<rank[i][j]<<" ";
                
                 
                if(grid[i][j]==1)ans=max(ans,rank[i][j]);
                else{
                int res=1;
                set<pair<int,int>> s;    
                for(int k=0;k<4;k++){
                        
                        int x=i+dx[k];
                        int y=j+dy[k];
                        
                        if(x>=0 && x<n && y<m && y>=0 && grid[x][y]==1){
                            
                            auto pa=findParent(x,y,parent);
                            x=pa.first;
                            y=pa.second;
                            if(s.count({x,y})==0){
                            s.insert({x,y});
                            res+=rank[x][y];
                            }    
                            
                            
                        }

                      }
                    
                    // for(auto c:s){
                    //     int x=c.first;
                    //     int y=c.second;

                    // }
                    
                    ans=max(ans,res);
                  } 
                    
                    
                    
                    
                    
                }
                // cout<<endl;
                
                
                
            }

        // cout<<parent[0][4].first<<" "<<parent[0][4].second<<"\n";
        
        
        
        return ans;
        
    }
};