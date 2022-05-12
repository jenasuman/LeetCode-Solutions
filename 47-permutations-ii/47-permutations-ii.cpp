class Solution {
public:
         vector<vector<int>> ans;
    set<vector<int>> temp;
    
    void solve(int x,vector<int> &nums){
        
        if(x==nums.size()){
            temp.insert(nums);
            return;
        }
        
        for(int i=x;i<nums.size();i++){
            
            if(i>x && nums[i]==nums[i-1])continue;
            
             swap(nums[i],nums[x]);
        
             solve(x+1,nums);
          
            swap(nums[i],nums[x]);       

            
        }
        
        
        return;
        
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      
        
        sort(nums.begin(),nums.end());
        
        solve(0,nums);
        
        for(auto i:temp){
            ans.push_back(i);
        }
        
        return ans;
        
    }
};