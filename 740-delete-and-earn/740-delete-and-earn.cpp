class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        
        //House Robber Type problem if we can sum the common terms
        
        vector<int> v;
        int sum=nums[0];
        for(int i=1;i<n;i++){
            
            if(nums[i]!=nums[i-1]){
                v.push_back(sum);
                sum=0;
                if(nums[i]-nums[i-1]!=1){
                    v.push_back(0);
                }
            }
            sum+=nums[i];
            
        }
        v.push_back(sum);
        n=v.size();
        vector<int> dp(n+1);
        dp[0]=0;
        dp[1]=v[0];
        
        for(int i=2;i<=n;i++){
            
            dp[i]=max(v[i-1]+dp[i-2],dp[i-1]);
            
            
        }
        
        return dp[n];
        
        
        
        
        
    }
};