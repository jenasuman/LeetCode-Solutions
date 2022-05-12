class Solution {
public:
    set<vector<int>> s;
    void solve(int index,vector<int>& nums){
        
        if(index==nums.size()){
        
            s.insert(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[index])continue;
            int x=index==0?0:(nums[i]+nums[index-1]);
            int y=index==0?0:sqrt(x);

            if(x==y*y){
                
                swap(nums[i],nums[index]);
                
                solve(index+1,nums);
                
                swap(nums[i],nums[index]);
                
                
            }
            
            
            
            
        }
        
        
    }
    int numSquarefulPerms(vector<int>& nums) {
        solve(0,nums);
        return s.size();
    }
};