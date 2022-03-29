class Solution {
public:
    int findDuplicate(vector<int>& nums) {
           int i=nums[0];
        while(nums[i]!=-1){
            
            int j=nums[i];
            
            nums[i]=-1;
            
            i=j;
            
            
            
        }
        
        return i;
    }
};