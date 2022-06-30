class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
         
        vector<int> ans;
        
        int n=nums.size();
        // int m=nums[0].size();
        
        
        map<int,vector<int>> adj;
        
        for(int i=0;i<n;i++){
             int m=nums[i].size();
            for(int j=0;j<m;j++){
            
                adj[i+j].push_back(nums[i][j]);
            
            }
            
        }
         
        for(auto u:adj){
            auto v=u.second;
            int l=v.size();
            
            for(int i=l-1;i>=0;i--){
                
                ans.push_back(v[i]);
                
                
            }
            
            
            
            
        }
        
        return ans;
        
    }
};