class Solution {
public:

    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size();
        
        vector<vector<int>> dp(n,vector<int>(1505,1));
        int ans=2;
        for(int i=0;i<n;i++){
            
            for(int j=0;j<i;j++){
                
                int diff=nums[i]-nums[j]+1000;
                dp[i][diff]=dp[j][diff]+1;
                
                ans=max(dp[i][diff],ans);
                
            }
            
            
            
            
        }
        
        return ans;
    }
};