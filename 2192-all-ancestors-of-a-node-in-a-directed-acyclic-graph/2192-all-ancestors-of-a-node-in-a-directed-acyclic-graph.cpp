class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<int>& v,vector<int> adj[]){
        
                
        for(auto c:adj[node]){
            if(vis[c]==0){
                vis[c]=1;
                v.push_back(c);
                dfs(c,vis,v,adj);
            }
        }
        
        return;
        
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

          vector<int> adj[n];
          
          for(auto v:edges){
             
                  adj[v[1]].push_back(v[0]);
              
          }
           vector<vector<int>> ans;
          for(int i=0;i<n;i++){
              vector<int> v;
              vector<int> vis(n,0);
              vis[i]=1;
              dfs(i,vis,v,adj);
              sort(v.begin(),v.end());
              ans.push_back(v);
          }
        return ans;
           
          
    }
};