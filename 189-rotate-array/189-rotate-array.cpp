class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,0);
        int index;
        for(int i=0;i<n;i++){
            index=(i+k)%n;
            ans[index]=nums[i];
        }
        
        nums=ans;
        
    }
};