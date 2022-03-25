class Solution {
public:
    int dp[101][101][101];
    int solve(int index,vector<vector<int>>& cost,int n,int group1,int group2){
        
        if(index>=n){
            return 0;
        }
        if(dp[index][group1][group2]!=-1)return dp[index][group1][group2];
        int case1=INT_MAX;
        int case2=INT_MAX;
        
        if(group1!=0){
            case1=cost[index][0]+solve(index+1,cost,n,group1-1,group2);
        }
        if(group2!=0){
          case2=cost[index][1]+solve(index+1,cost,n,group1,group2-1);            
        }
        
        
        return dp[index][group1][group2]=min(case1,case2);
        
        
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        int m=n/2;
        memset(dp,-1,sizeof(dp));
        return solve(0,costs,n,m,m);
        
        
    }
};