class Solution {
public:

    int smallestRangeII(vector<int>& nums, int k) {
        
          sort(nums.begin(),nums.end());
          int n=nums.size();
          
          int ma=nums[n-1];
          int mi=nums[0];
        
          int ans=ma-mi;
        
          for(int i=0;i<n-1;i++){
              
              ma=max(nums[i]+k,nums[n-1]-k);
              mi=min(nums[0]+k,nums[i+1]-k);
              
              ans=min(ans,ma-mi);
              
              
          }
          
        
        return ans;
        
        
        
        
        
    }
};