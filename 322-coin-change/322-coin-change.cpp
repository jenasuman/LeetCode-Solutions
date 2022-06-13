class Solution {
//     int n;
//     int dp[14][10004];
//     int f(int i,vector<int>& coins,int amount){
        
//         if(amount==0)return 0;
//         if(i<0 && amount){
//             return INT_MAX;
//         }
//         if(dp[i][amount]!=-1)return dp[i][amount];
//         int take=INT_MAX;
//         int notTake=INT_MAX;
        
//         if(coins[i]<=amount){
            
//             int ans=f(i,coins,amount-coins[i]);
//             take=(ans!=INT_MAX)?(1+ans):INT_MAX;
            
//         }
//         notTake=f(i-1,coins,amount);
        
//         return dp[i][amount]=min(take,notTake);
//     } 
    
    
public:
    int coinChange(vector<int>& coins, int amount) {
        // memset(dp,-1,sizeof(dp));
        int n=coins.size();
        
        vector<vector<int>> dp(n+1,vector<int>(amount+1,INT_MAX));
        
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        
        for(int i=1;i<=n;i++){
            
            for(int a=1;a<=amount;a++){
                
        int take=INT_MAX;
        int notTake=INT_MAX;
        
        if(coins[i-1]<=a){
            
            int ans=dp[i][a-coins[i-1]];
            take=(ans!=INT_MAX)?(1+ans):INT_MAX;
            
        }
        notTake=dp[i-1][a];
                
        dp[i][a]=min(take,notTake);        
                
                
                
                
                
                
       }
            
            
            
            
        }
        
        
        
        return dp[n][amount]==INT_MAX?-1:dp[n][amount];
    }
};