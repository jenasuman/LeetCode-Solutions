class Solution {
public:

    bool checkSubarraySum(vector<int>& nums, int k) {
        
        
        vector<int> temp(nums);
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
            
            if(temp[i]==0 && temp[i-1]==0)return true;
        }
        
        for(int i=1;i<n;i++){
            
            if(nums[i]%k==0)return true;
            
            for(int j=0;j<i-1;j++){
                
                if(nums[i]-nums[j]<k)break;
                if((nums[i]-nums[j])%k==0)return true;
                
                
                
                
                
                
            }
            
            
            
        } 
        
        return false;
    }
};