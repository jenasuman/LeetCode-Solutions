class Solution {
    void dfs(int i,vector<vector<int>>& g,vector<int>& vis){
        
        vis[i]=1;
        
        for(auto c:g[i]){
            if(vis[c]==0){
                dfs(c,g,vis);
            }
        }
        
        
        
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        
        vector<vector<int>> g(n);
        int edges=connections.size();
        int count=0;
        for(auto v:connections){
            if(g[v[0]].size()==0)count++;
            if(g[v[1]].size()==0)count++;
            g[v[0]].push_back(v[1]);
            g[v[1]].push_back(v[0]);
            
        }
        edges-=(count-1);
        // cout<<edges<<"\n";
        // vector<int> parent(n,-1);
        
        vector<int> vis(n,0);
        
        int nos=0;
        for(int i=0;i<n;i++){
           
        if(vis[i]==0){
            
            nos++;
            
            dfs(i,g,vis);
            
            
        }
        
        
        }     
        
        
        
        
        
        
        
        
        
        // nos= Number of sets
        return (nos-1)<=edges?(nos-1):-1;
    }
};