class Solution {
    vector<vector<int>> bridges;
    void f(int node,int parent,vector<int>& tin,vector<int>& tlow,int& timer,vector<bool>& vis,vector<int> adj[]){
        
        vis[node]=true;
        tin[node]=timer;
        tlow[node]=timer;
        timer++;
        
        
        for(auto c:adj[node]){
            
            if(c==parent)continue;
            
            if(vis[c]==false){
                
                f(c,node,tin,tlow,timer,vis,adj);
                
                tlow[node]=min(tlow[c],tlow[node]);
                
                if(tlow[c]>tin[node]){
                    // cout<<"hello"<<"\n";
                    bridges.push_back({node,c});
                    
                }
                
                
                
                
                
            }
            else{
                tlow[node]=min(tlow[node],tin[c]);
            }
            
            
            
            
        }
        
        
        
        
        
        
        
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
         
        vector<int> tin(n,-1);
        vector<int> tlow(n,-1);
        vector<bool> vis(n,false);
        
        vector<int> adj[n];
        
        for(auto v:connections){
        
            adj[v[1]].push_back(v[0]);
            adj[v[0]].push_back(v[1]);
            
        }
        int timer=0;
        for(int i=0;i<n;i++){
        if(vis[i]==false)    
        f(i,-1,tin,tlow,timer,vis,adj);
        }
        return bridges;
        
        
        
        
    }
};