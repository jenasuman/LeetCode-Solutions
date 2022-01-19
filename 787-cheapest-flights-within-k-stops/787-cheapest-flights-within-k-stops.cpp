class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto v:flights){
            adj[v[0]].push_back({v[1],v[2]});
        }
        
        vector<int> price(n,INT_MAX);
        
        int countStops=0;
        
        queue<pair<int,int>> q;
        q.push({src,0});
        int ans=INT_MAX;
        
        while(!q.empty() && countStops<=k){
            
            int n=q.size();
            
            for(int i=0;i<n;i++){
                
                auto t=q.front();
                
                int s=t.first;
                int p=t.second;
                
                q.pop();
                
                if(p>price[s])continue;
                
                price[s]=p;
                
                
                
                for(auto c:adj[s]){
                    
                    
                    
                   if(ans<p+c.second)continue;
                    
                   if(c.first==dst)ans=min(ans,price[s]+c.second);
                   
                    q.push({c.first,price[s]+c.second});
                
                    
                    
                }
                
                
                
                
                
            }
            countStops++;
            
            
            
            
            
        }
        
        return ans!=INT_MAX?ans:-1;
        
    }
};