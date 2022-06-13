class Solution {
    int n;
    int dp[2501][2502];
    int f(int prev,int curr,vector<int>& nums){
        
        if(curr==n){
            return 0;
        }
        
        if(dp[curr][prev+1]!=-1)return dp[curr][prev+1];
        
        int l1=f(prev,curr+1,nums);
        int l2=0;
        if(prev==-1 || nums[curr]>nums[prev]){
         l2=1+f(curr,curr+1,nums);
        }
    
        
        return dp[curr][prev+1]=max(l1,l2);
        
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        
        // nums.insert(nums.begin(),-10000);
        memset(dp,-1,sizeof(dp));
        int i=-1;
        int j=0;
        n=nums.size();
        
        return f(i,j,nums);
        
        
        
        
    }
};