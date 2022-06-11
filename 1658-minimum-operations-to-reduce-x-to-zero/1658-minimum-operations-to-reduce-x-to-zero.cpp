class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        int n=nums.size();
        
        int sum=accumulate(nums.begin(),nums.end(),0);
        
        if(sum<x)return -1;

        
        int target=sum-x;
        
        int j=0;
        
        int i=0;
        
        int ans=INT_MAX;
        sum=0;
        for(int i=0;i<n;i++){
            
            sum+=nums[i];
            
            while(j<n && sum>target){
                
                sum-=nums[j];
                j++;
                
                
            }
            
            if(sum==target){
                
                ans=min(ans,n-(i-j+1));
                
            }
            
            
            
        }
        
        return ans==INT_MAX?-1:ans;
        
        
    }
};