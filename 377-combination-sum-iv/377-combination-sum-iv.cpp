class Solution {
    int dp[1001];
    int f(vector<int>& nums,int target){
        
        
        if(target==0)return 1;
        
        // if(i==nums.size())return 0;
        if(dp[target]!=-1)return dp[target];
        int case1=0;
  
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=target){
                case1+=f(nums,target-nums[i]);
            }
       
        }
        
        return dp[target]=case1;
        
    }
    
public:
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return f(nums,target);
    }
};