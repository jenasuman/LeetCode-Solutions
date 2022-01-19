class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)     {
                
        unordered_map<int,vector<pair<int,double>>> adj;
        
        int m=edges.size();
        
        for(int i=0;i<m;i++){
            
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
            
        }
          vector<int> seen(n,0);
         priority_queue <pair<double,int>> pq;
        
         vector<double> ans(n,0);
        
         pq.push({1,start});
        
         while(!pq.empty()){
             
             auto p=pq.top();
             pq.pop();
             
             int cNode=p.second;
             double cProb=p.first;
             
             
             if(cProb<=ans[cNode]){
                 continue;
             }
             
             ans[cNode]=cProb;
             
             if(seen[cNode]==0){
             seen[cNode]++;    
             for(auto c:adj[cNode]){
                 
              
                 pq.push({c.second*cProb,c.first});
                 
                 
                 
                 
             }
             }
             
             
             
             
         }
        
        
        return ans[end];
        
        
    }
};