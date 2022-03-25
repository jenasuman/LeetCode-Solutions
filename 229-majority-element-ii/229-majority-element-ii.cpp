class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        int m=n/3;
        
        int count=1;
        vector<int> ans;
        for(int i=1;i<n;i++){
            
            if(nums[i]!=nums[i-1]){
                if(count>m){
                    ans.push_back(nums[i-1]);
                }
                count=1;
            }
            else{
                count++;
            }
            
            
        }
        if(count>m)ans.push_back(nums[n-1]);
        return ans;
        
    }
};