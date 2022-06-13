class Solution {
    int n;
    int dp[13][10002];
    int f(int i,vector<int>& coins,int amount){
        
        if(amount==0)return 0;
        if(i<0 && amount){
            return INT_MAX;
        }
        if(dp[i][amount]!=-1)return dp[i][amount];
        int take=INT_MAX;
        int notTake=INT_MAX;
        
        if(coins[i]<=amount){
            
            int ans=f(i,coins,amount-coins[i]);
            take=(ans!=INT_MAX)?(1+ans):INT_MAX;
            
        }
        notTake=f(i-1,coins,amount);
        
        return dp[i][amount]=min(take,notTake);
    } 
public:
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        n=coins.size();
        int i=n-1;
        int ans=f(i,coins,amount);
        return ans==INT_MAX?-1:ans;
    }
};