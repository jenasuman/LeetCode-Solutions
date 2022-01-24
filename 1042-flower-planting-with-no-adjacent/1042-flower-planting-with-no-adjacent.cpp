class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> adj[n+1];
        
        for(auto v:paths){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<int> flower(n,0);
        
        for(int i=1;i<=n;i++){
            
        if(flower[i-1]==0){    
        flower[i-1]=1;
        
        queue<int> q;
        q.push(i);
        
        while(!q.empty()){
             int t=q.front();
             q.pop();
             int colour=flower[t-1]; 
        
             for(auto c:adj[t]){
                
                 
                 if(flower[c-1]==0){
                             
                   if(colour==4){
                       flower[c-1]=1;
                   }
                   else{
                       flower[c-1]=colour+1;
                   } 
                   q.push(c);  
                     
                 }
                 else if(colour==flower[c-1]){
                       if(colour==4){
                       flower[c-1]=1;
                   }
                   else{
                       flower[c-1]=colour+1;
                   }  
                     
                     
                     
                     
                 }
                 
                 
                 
             }
              
        }
        }
            
        }    
        return flower;
        
    }
};