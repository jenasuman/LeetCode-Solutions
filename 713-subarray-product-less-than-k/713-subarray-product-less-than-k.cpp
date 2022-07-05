class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        
        int ans=0;
        
        int j=0;
        
        int n=nums.size();
        
        int productTillNow=1;
        
        for(int i=0;i<n;i++){
            
            productTillNow*=nums[i];
            
            while(productTillNow>=k && j<=i){
                productTillNow/=nums[j];
                j++;
            }
        
            ans+=(i-j+1);
            
            
            
        }
        
        return ans;
        
    }
};