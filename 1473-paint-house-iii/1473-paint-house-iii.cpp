class Solution {
    int dp[101][22][101];
    int f(int i,int prev,vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target){
        
        if(i!=m && target<0){
            return INT_MAX;
        }
        
        if(i==m){
               
            if(target==0){
                return 0;
            }
            else{
                return INT_MAX;
            }
   
        }
        if(dp[i][prev][target]!=-1)return dp[i][prev][target];
        if(houses[i]!=0){
             if(prev!=houses[i])
             return f(i+1,houses[i],houses,cost,m,n,target-1);
             else return f(i+1,prev,houses,cost,m,n,target);
        }
        
        int ans=INT_MAX;
        for(int j=1;j<=n;j++){
            
            
            int restCost;
            if(j==prev)
            restCost=f(i+1,prev,houses,cost,m,n,target);
            else{
            restCost=f(i+1,j,houses,cost,m,n,target-1);    
            }
            if(restCost!=INT_MAX){
            int temp=cost[i][j-1]+restCost;
            ans=min(temp,ans);
            }    
           

        }
        
        return dp[i][prev][target]=ans;
        
        
    }
    
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(dp,-1,sizeof(dp));
        int ans=f(0,0,houses,cost,m,n,target);
        return ans==INT_MAX?-1:ans;
        
        
    }
};