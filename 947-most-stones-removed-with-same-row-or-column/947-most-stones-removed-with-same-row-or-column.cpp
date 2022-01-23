class Solution {
public:
    void solve(int index,vector<int> adj[],int& count,vector<int>& visited){
        
        count++;
        
        visited[index]=1;
        
        for(auto c:adj[index]){
            
            if(visited[c]==0){
                solve(c,adj,count,visited);
            }
            
        }
        
        return;
        
    }
    int removeStones(vector<vector<int>>& stones) {
        
        int n=stones.size();
        
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               
               if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                   adj[i].push_back(j);
                   adj[j].push_back(i);
               }
               
               
           } 
        }
        
        vector<int> visited(n,0);
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            if(visited[i]==0){
                
                int count=0;
                
                solve(i,adj,count,visited);
                
                ans+=count-1;
                
                
            }
            
            
            
            
        }
        
        return ans;
        
        
    }
};