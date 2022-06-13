class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        
        vector<int> dp(201,INT_MAX);
        dp[0]=t[0][0];
        
        
        int n=t.size();
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            vector<int> temp(201,INT_MAX);
            for(int j=0;j<t[i].size();j++){
                
                if(j!=0)
                temp[j]=t[i][j]+min(dp[j],dp[j-1]);
                else
                temp[j]=t[i][j]+dp[j];    
             
                 
            }
            
            // cout<<"\n";
            dp=temp;
            
        }
 
        for(int i=0;i<n;i++){
            ans=min(ans,dp[i]);
        }
    
        
        return ans;
    }
};