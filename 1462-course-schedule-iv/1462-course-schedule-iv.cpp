class Solution {
public:
    void dfs(int index,vector<int> adj[],vector<bool>& vis,vector<vector<int>>& d,int source){
        
        if(index!=source){
            d[source][index]=1;
        }
        
        vis[index]=true;
        
        
        
        for(auto c:adj[index]){
            
            if(vis[c]==false){
                dfs(c,adj,vis,d,source);
            }
            
            
        }
       
        
        
    }
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        
        vector<int> adj[n];
        vector<int> inorder(n,0);
        
        for(auto v:pre){
            adj[v[1]].push_back(v[0]);
        }
        
        vector<vector<int>> isReachable(n,vector<int>(n,0)) ;
        
        
        for(int i=0;i<n;i++){
            
            vector<bool> vis(n,false); 
            dfs(i,adj,vis,isReachable,i);
            
            
        }
       
        vector<bool> ans;
        for(auto v:q){
           
            if(isReachable[v[1]][v[0]]==1){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
            
            
            
        }
        
        return ans;
        
    }
};