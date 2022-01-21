class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        
        vector<int> adj[n+1];
        
        for(auto v:dislikes){
            
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int> group(n+1,-1);
        
        for(int i=1;i<=n;i++){
        
        if(group[i]==-1){    
        queue<int> q;
        
        q.push(i);
        
        group[i]=1;
        
        while(!q.empty()){
            
            int index=q.front();
            q.pop();
            for(auto c:adj[index]){
                if(group[c]==-1){
                    group[c]=group[index]==0?1:0;
                    q.push(c);
                }
                else if(group[c]==group[index]){
                    return false;
                }
                
            }
            
            
            
        }
        }
        }
        return true;
    }
};