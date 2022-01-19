
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int t) {
        // We have to call dijstra in every node of the graph 
        
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto v:edges){
            
            adj[v[0]].push_back({v[1],v[2]});
            adj[v[1]].push_back({v[0],v[2]});
            
        }
        int miCities=INT_MAX;
        int index=-1;
        
        for(int i=0;i<n;i++){
            
            vector<int> dis(n,INT_MAX);
            
            priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
            
            pq.push({0,i});
            
            while(!pq.empty()){
                
                auto p=pq.top();
                pq.pop();
                
                int cNode=p.second;
                int cDist=p.first;
                
                if(cDist>dis[cNode]){
                    continue;
                }
                
                dis[cNode]=cDist;
                
                for(auto c:adj[cNode]){
                    
                      pq.push({cDist+c.second,c.first});
                
                 }
                
             }
            
            int count=0;
            
            for(auto d:dis){
                if(d<=t){
                    count++;
                }
            }
            
            count-=1;
            
            if(count<=miCities){
                
                miCities=count;
                index=i;
                
            }
            
            
            
            
            
           }
         
        return index!=-1?index:-1;
        
        
    }
};