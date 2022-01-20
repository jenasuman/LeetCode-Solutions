class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int> adj[n];
        
        for(int i=0;i<n;i++){
            for(auto c:graph[i]){
                adj[i].push_back(c);
            }
        }
        
        vector<int> colour(n,-1);
        
        for(int i=0;i<n;i++){
            
            if(colour[i]==-1){
                
                colour[i]=0;
                
                queue<int> q;
                
                q.push(i);
                
                bool flag=true;
                
                while(!q.empty()){
                    
                    int t=q.front();
                    q.pop();
                    
                    for(auto c:adj[t]){
                        
                        if(colour[c]==-1){
                            
                            colour[c]=colour[t]==0?1:0;
                            
                            q.push(c);
                            
                            
                        }
                        else{
                            
                            if(colour[c]==colour[t]){
                                flag=false;
                                break;
                            }
                            
                        }
                        
                        
                        
                        
                    }
                    
                    
                    
                    
                    
                }
                
                if(flag==false)return false;
                
                
            }
            
            
            
        }
        
        
        return true;
        
    }
};