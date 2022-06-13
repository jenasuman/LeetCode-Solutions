class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        
        vector<vector<int>> dp(201,vector<int>(201,INT_MAX));
        dp[0][0]=t[0][0];
        
        
        int n=t.size();
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            
            for(int j=0;j<t[i].size();j++){
                
                if(j!=0)
                dp[i][j]=t[i][j]+min(dp[i-1][j],dp[i-1][j-1]);
                else
                dp[i][j]=t[i][j]+dp[i-1][j];    
             
                 
            }
            
            // cout<<"\n";
            
        }
 
        for(int i=0;i<n;i++){
            ans=min(ans,dp[n-1][i]);
        }
    
        
        return ans;
    }
};