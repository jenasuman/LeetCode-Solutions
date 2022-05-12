class Solution {
public:
    set<vector<int>> s;
    void solve(int index,vector<int>& nums){
        
        if(index==nums.size()){
            // for(auto i:nums)cout<<i<<" ";
            // cout<<endl;
            s.insert(nums);
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[index])continue;
            int x=nums[i]+nums[index-1];
            int y=sqrt(x);
            // cout<<x<<" "<<y*y<<"\n";
            if(index==1 || x==y*y){
                
                swap(nums[i],nums[index]);
                
                solve(index+1,nums);
                
                swap(nums[i],nums[index]);
                
                
            }
            
            
            
            
        }
        
        
    }
    int numSquarefulPerms(vector<int>& nums) {
        
        // ans=0;
        vector<int> temp;
        temp.push_back(0);
        for(auto i:nums)temp.push_back(i);
        solve(1,temp);
        return s.size();
    }
};