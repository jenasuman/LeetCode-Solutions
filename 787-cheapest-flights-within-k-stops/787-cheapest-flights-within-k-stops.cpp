class Solution {
    unordered_map<int,vector<pair<int,int>>> adj;
    
public:
    int dp[100][100];
    int f(int src,int dst,int k){
         

        
        if(src==dst){
            return 0;
        }
        
        if(k<0){
            return INT_MAX;
        }
        if(dp[src][k]!=-1)return dp[src][k];
        int ans=INT_MAX;
                    
        for(auto c:adj[src]){
            
            int curr=c.first;
            int price=c.second;
            int res=f(curr,dst,k-1);
            // cout<<res<<"\n";
            if(res!=INT_MAX)
            ans=min(ans,price+res);
            
            
        }
        
        return dp[src][k]=ans;
        
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        for(auto v:flights){
            adj[v[0]].push_back({v[1],v[2]});
        }
        memset(dp,-1,sizeof(dp));
        int ans=f(src,dst,k);
        return ans==INT_MAX?-1:ans;
        
    }
};