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
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
         
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            
            for(auto c:rooms[i]){
                adj[i].push_back(c);
            }
            
         }
        
         
        vector<bool> visited(n,false);
        
        dfs(0,adj,visited);
        
        for(auto i:visited){
            if(i==false)return false;
        }
        
         return true;
        
    }
};