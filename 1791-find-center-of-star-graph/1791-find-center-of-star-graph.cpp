class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
        
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
            }
        
        int n=adj.size();
        
        for(auto v:adj){
            int m=v.second.size();
            if(m==n-1)return v.first;
        }
        return -1;
    }
};