class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
 
        //House Robber Type problem if we can sum the common terms
        
        vector<int> v(10002);
   
        for(int i=0;i<n;i++){
            
           v[nums[i]]+=nums[i];
            
        }
  
        vector<int> dp(10002);
        dp[0]=0;
        dp[1]=v[0];
        
        for(int i=2;i<=10001;i++){
            
            dp[i]=max(v[i-1]+dp[i-2],dp[i-1]);
            
            
        }
        
        return dp[10001];
        
        
        
        
        
    }
};