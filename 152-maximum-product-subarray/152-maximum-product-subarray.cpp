class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int minProduct=1;
        int maxProduct=1;
        
        int n=nums.size();
        
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            
            
            int tminProduct=min({nums[i],nums[i]*minProduct,nums[i]*maxProduct});
            int tmaxProduct=max({nums[i],nums[i]*minProduct,nums[i]*maxProduct});
            
            minProduct=tminProduct;
            maxProduct=tmaxProduct;
            
            ans=max(ans,maxProduct);
            
        }
       
        return ans;
        
        
    }
};