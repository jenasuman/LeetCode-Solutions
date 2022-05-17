class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
         
        int n=nums.size();
        
        int left=0;
        int right=0;
        
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]){
                left=i;
                break;
            }
        }
        
        for(int i=n-1;i>0;i--){
            if(nums[i]<nums[i-1]){
                right=i;
                break;
            }
            
        }
        
        int ans=right-left+1;
        
        if(right==left)return 0;
        
        int ma=INT_MIN;
        int mi=INT_MAX;
        
        for(int i=left;i<=right;i++){
            ma=max(ma,nums[i]);
            mi=min(mi,nums[i]);
        }
        
        while(left-1>=0 && nums[left-1]>mi){
            ans++;
            left--;
        }
        
        while(right+1<n && nums[right+1]<ma){
            ans++;
            right++;
        }
        return ans;
    }
};