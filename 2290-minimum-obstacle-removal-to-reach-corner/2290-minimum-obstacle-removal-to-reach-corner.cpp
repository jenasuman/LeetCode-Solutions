class Solution {
public:
     
    using t=tuple<int,int,int>; 
    int minimumObstacles(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1}; 
        
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
    
        priority_queue<t,vector<t>,greater<t>> pq;
        
        pq.push({grid[0][0],0,0});
        
        dp[0][0]=0;
        
        while(!pq.empty()){
            

            auto [d,x,y]=pq.top();
            pq.pop();
            
            if(x==n-1 && y==m-1)return d;
            
            for(int i=0;i<4;i++){
                
                
                int cx=dx[i]+x;
                int cy=dy[i]+y;
                
                if(cx>=0 && cy>=0 && cy<m && cx<n){
                    
                    
                    if(d+grid[cx][cy]<dp[cx][cy]){
                        
                        
                        dp[cx][cy]=d+grid[cx][cy];
                        
                        pq.push({dp[cx][cy],cx,cy});
                        
                        
                    }
                    
                    
                    
                    
                    
                }
                
                
                
                
            }
            
            
            
            
            
            
            
        }
        
        
        
        return -1;
        
    }
};