class Solution {
public:
   int dp[101][101];
    int f(int i,int j,vector<int>& cuts){
        
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            
            int cost=cuts[j+1]-cuts[i-1]+f(k+1,j,cuts)+f(i,k-1,cuts);
            ans=min(cost,ans);
            
        }
        
        return dp[i][j]=ans;
        
    }
    int minCost(int n, vector<int>& cuts) {
        
        cuts.push_back(n);
        cuts.insert(begin(cuts),0);
        sort(begin(cuts),end(cuts));
        int m=cuts.size();
        memset(dp,-1,sizeof(dp));
        return f(1,m-2,cuts);
        
    }
};