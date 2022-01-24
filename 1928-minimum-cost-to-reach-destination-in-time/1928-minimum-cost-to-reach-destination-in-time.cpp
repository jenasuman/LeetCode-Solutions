class Solution {
public:
    unordered_map<int,vector<pair<int,int>>> m;
    vector<int> fees;
    vector<vector<int>> dp;
    int solve(int n,int maxTime){
        
        if(maxTime<0)return -1;
        if(dp[n][maxTime]!=-1){
            return dp[n][maxTime]==INT_MAX?-1:dp[n][maxTime];
        }
        if(n==0)return fees[0];
       
        
        int cost=INT_MAX;
        
        for(auto& p:m[n]){
            
            int c=solve(p.first,maxTime-p.second);
            
            if(c!=-1){
                cost=min(cost,c+fees[n]);
            }
            
            
            
            
        }
        
        dp[n][maxTime]=cost;
        return cost==INT_MAX?-1:cost;
        
    }
    
    
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
            
        for(auto v:edges){
            m[v[0]].push_back({v[1],v[2]});
              m[v[1]].push_back({v[0],v[2]});
        }
        int n=passingFees.size();
        
        dp=vector<vector<int>>(1001,vector<int>(1001,-1));
        
        fees=move(passingFees);
        
        return solve(n-1,maxTime);
            
        
    }
};