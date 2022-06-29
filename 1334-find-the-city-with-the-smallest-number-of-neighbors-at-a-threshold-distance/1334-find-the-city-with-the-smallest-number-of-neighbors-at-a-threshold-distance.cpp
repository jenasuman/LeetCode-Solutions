class Solution {
    using p=pair<int,int>;
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        
        int ans=-1;
        
        vector<p> adj[n];
        
        for(auto v:edges){
            
            adj[v[1]].push_back({v[0],v[2]});
            adj[v[0]].push_back({v[1],v[2]});
            
            
        }
        
        int count=103;
        for(int i=0;i<n;i++){
            
            vector<int> dis(n,INT_MAX);
            
            priority_queue<p,vector<p>,greater<p>> pq;
            
            pq.push({0,i});
            
            dis[i]=0;
            
            while(!pq.empty()){
                
               int d=pq.top().first;
                
               int index=pq.top().second;
                
               pq.pop(); 
                
                
               for(auto c:adj[index]){
                   
                   int wt=c.second;
                   int j=c.first;
                   
                   if(d+wt<dis[j]){
                       
                       dis[j]=d+wt;
                       
                       pq.push({dis[j],j});
                       
                       
                   }
                   
                   
                   
                   
               } 
                
                
                
                
                
            }
            
            int tempCount=0;
            
            for(auto k:dis){
                if(k<=distanceThreshold)tempCount++;
            }
            
            if(tempCount<=count && tempCount!=0){
                count=tempCount;
                ans=i;
            }
            
            
            
            
        }
        
        return ans;
        
        
        
        
    }
};