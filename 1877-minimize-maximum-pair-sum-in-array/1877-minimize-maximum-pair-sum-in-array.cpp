class Solution {
public:
    int minPairSum(vector<int>& nums) {
        
        sort(begin(nums),end(nums));
        
        int i=0;
        int j=nums.size()-1;
        
        int ans=INT_MIN;
        
        while(i<j){
            
            ans=max(ans,nums[i]+nums[j]);
            i++;
            j--;
            
            
            
        }
        
        return ans;
        
    }
};