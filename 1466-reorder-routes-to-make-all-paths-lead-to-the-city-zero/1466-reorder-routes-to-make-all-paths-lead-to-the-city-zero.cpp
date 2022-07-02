class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        
        vector<pair<int,char>> adj[n];
        
        for(auto v:connections){
            
            adj[v[0]].push_back({v[1],'o'});
            adj[v[1]].push_back({v[0],'i'});
            
            
        }
        
        queue<int> q;
        vector<int> vis(n,0);
        q.push(0);
        vis[0]=1;
        
        int ans=0;
        
        while(!q.empty()){
            
            int p=q.front();
            q.pop();
            
            for(auto i:adj[p]){
                
                int c=i.first;
                char d=i.second;
                if(vis[c]==0){
                    vis[c]=1;
                    if(d=='o'){
                        ans++;
                    }
                    q.push(c);
                    
                    
                }
                
                
                
                
                
            }
            
            
            
            
            
            
        }
        
        
        
        return ans;
    }
};