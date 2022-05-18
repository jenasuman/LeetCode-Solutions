class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<j)
        {
            
            int currSum=nums[i]+nums[j];
            
            if(currSum==k){
                i++;
                j--;
                ans++;
            }
            else if(currSum>k)j--;
            else i++;
            
            
            
            
        }        
        
        return ans;
    }
};