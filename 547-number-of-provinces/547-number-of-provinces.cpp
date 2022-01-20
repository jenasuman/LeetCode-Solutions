class Solution {
public:
    void dfs(int index,vector<int> adj[],vector<bool>& visited){
        
        visited[index]=true;
        
        for(auto c:adj[index]){
            if(visited[c]==false){
                dfs(c,adj,visited);
            }
        }
        
        
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> adj[n];
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
                
                
            }
            
        }
        
        int count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                count++;
                dfs(i,adj,visited);
            }
        }
        
        
        return count;
        
    }
};