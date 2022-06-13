class Solution {
public:
    int solve(string &text1, string& text2,int n,int m,vector<vector<int>>& dp){
        
        if(n==0 || m==0)return 0;
        
        if(dp[n][m]!=-1)return dp[n][m];
        
        if(text1[n-1]==text2[m-1]){
            
            dp[n][m]=1+solve(text1,text2,n-1,m-1,dp);
            
            
        }
        else{
            
            dp[n][m]=max(solve(text1,text2,n-1,m,dp),solve(text1,text2,n,m-1,dp));
            
        }
        
        return dp[n][m];
        
        
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
        
        // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        vector<int> dp(m+1,0);
        
        for(int i=1;i<=n;i++){
            vector<int> temp(m+1,0);
            for(int j=1;j<=m;j++){
                
                if(text1[i-1]==text2[j-1]){
                    temp[j]=1+dp[j-1];
                }
                else{
                    
                    temp[j]=max(dp[j],temp[j-1]);
                    
                }
                
                
            }
            dp=temp;
        }
        
        return dp[m];
        
    }
};