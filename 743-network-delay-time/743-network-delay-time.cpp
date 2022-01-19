class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int,vector<pair<int,int>>> adj;
        
        for(auto v:times){
            adj[v[0]].push_back({v[1],v[2]});
        }
        
        queue<int> q;
        
        q.push(k);
        
        vector<int> time(n+1,INT_MAX);
        
        time[0]=0;
        time[k]=0;
        
        while(!q.empty()){
            
            int t=q.front();
            
            q.pop();
            
            for(auto p:adj[t]){
                int node=p.first;
                
                if(time[node]>time[t]+p.second){
                    time[node]=time[t]+p.second;
                    q.push(node);
                }
                
                
            }
            
            
            
            
        }
        
        int ans=INT_MIN;
        
        for(auto i:time){
            if(i==INT_MAX)return -1;
            ans=max(ans,i);
        }
        return ans;
        
    }
};