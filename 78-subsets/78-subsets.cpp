class Solution {
public:
    vector<vector<int>> ans;
    
    void calc(int x,vector<int> nums,vector<int> &v){
        
        ans.push_back(v);
        
        
        for(int i=x;i<nums.size();i++){
            
            if(i>x && nums[i]==nums[i-1])continue;
            
            v.push_back(nums[i]);
                
            calc(i+1,nums,v);
            
            v.pop_back();
            
            
        }
        
        
        return;
        
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<int> v;
        
        sort(nums.begin(),nums.end());
        
        calc(0,nums,v);
        
        return ans;
        
        
        
    }
};