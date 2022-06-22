class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        int n=nums.size();
        vector<int> ans(n);
        
        sort(nums.begin(),nums.end(),greater<int>());
        
        int j=0;
        for(int i=0;i<n;i++){
            if(i%2!=0){
                ans[i]=nums[j++];
            }
        }
        
        for(int i=0;i<n;i++){
            
            if(i%2==0){
                
                ans[i]=nums[j++];
                
            }
            
            
        }
        
        
        return ans;
        
    }
};