class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int countZeros=0;
        int n=nums.size();
        vector<int> ans(n,0);
        long long int product=1;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)product*=nums[i];
            else countZeros++;
        }
        
        if(countZeros>1)return ans;
        else{
            
            for(int i=0;i<n;i++){
                
                if(nums[i]==0)ans[i]=product;
                else if(countZeros==0) ans[i]=product/nums[i];
            
            }
            
            
        }        
        
        return ans;
    }
};