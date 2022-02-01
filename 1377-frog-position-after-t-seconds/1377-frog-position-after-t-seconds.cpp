class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<int> adj[n+1];
        
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int> vis(n+1,0);
        
        queue<int> q;
        vector<double> prob(n+1,0);
        q.push(1);
        prob[1]=1.0;
        vis[1]=1;
        
        while(!q.empty() && t--){
            
            int m=q.size();
            
            for(int i=0;i<m;i++){
                
                int t=q.front();
                q.pop();
                int cnt=0;
                
                for(auto c:adj[t]){
                    if(vis[c]==0)cnt++;
                }
                
                for(auto c:adj[t]){
                    
                    if(vis[c]==0){
                        
                        q.push(c);
                        vis[c]=1;
                        prob[c]=prob[t]/cnt;
                        
                    }
                    
                    
                    
                }
                
                
                if(cnt>0)prob[t]=0;
                
                
                
                
                
                
                
            }
            
            
            
            
            
            
        }
        
        return prob[target];
        
        
    }
};