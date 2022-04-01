class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            
            if(i>0 && nums[i]==nums[i-1])continue;
            
            
            int j=i+1;
            int k=n-1;
            int sum=nums[i];
            while(j<k){
                
                int temp=sum+nums[k]+nums[j];
                
                if(temp>0)k--;
                else if(temp<0)j++;
                else{
                    
                    ans.push_back({nums[i],nums[j],nums[k]});
                    k=k-1;
                    j=j+1;
                    while(k>j && nums[k]==nums[k+1])k--;
                    while(j<k && nums[j]==nums[j-1])j++;
                    
                    
                    
                }
                
                
                
                
                
                
            }
            
            
            
            
            
        }
        
        return ans;
        
    }
};