class Solution {
public:
   
    int solve(int i,int n,vector<int>& nums,int target,map<pair<int,int>,int>& dp){
        if(i==n){
             if(target==0){
                 return 1;
             }
             return 0;
        }
        
        if(dp.find({i,target})!=dp.end()){
            return dp[{i,target}];
        }
        
        int ans1=solve(i+1,n,nums,target-nums[i],dp);
        int ans2=solve(i+1,n,nums,target+nums[i],dp);
        
        return dp[{i,target}]=ans1+ans2;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
         int n=nums.size();
         map<pair<int,int>,int> dp;
         solve(0,n,nums,target,dp);
         return dp[{0,target}];
    }
};