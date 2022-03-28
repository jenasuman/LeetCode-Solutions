class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int ans=0;
        int s=0;
        int e=0;
        int n=nums.size();
        
        int windowSize=0;
        
        
        for(;e<n;e++){
            
            if(nums[e]<=right && nums[e]>=left){
                windowSize=e-s+1;
            }
            else if(nums[e]>right){
                windowSize=0;
                s=e+1;
            }
            else if(nums[e]<left){
                windowSize=windowSize;
            }
            
            ans+=windowSize;
            
            
        }
        return ans;
    }
};