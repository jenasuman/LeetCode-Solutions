class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> graph;
        
        for(auto v:times){
            graph[v[0]].push_back({v[1],v[2]});
        }
        
        vector<int> time(n+1,INT_MAX);
        
        time[0]=0;
        
        queue<int> pq;
        time[k]=0;
        pq.push(k);
        
        while(!pq.empty()){
            auto p=pq.front();
            pq.pop();
          
            for(auto c:graph[p]){
                int x=c.second;
                int y=c.first;
                if(time[y]>time[p]+x){
                time[y]=time[p]+x;    
                pq.push(y);
                }
            }
            
            
            
            
        }
        
        int ans=INT_MIN;
        
        for(auto i:time){
            // cout<<i<<" ";
            if(i==INT_MAX)return -1;
            ans=max(i,ans);
        }
        return ans;
    }
};