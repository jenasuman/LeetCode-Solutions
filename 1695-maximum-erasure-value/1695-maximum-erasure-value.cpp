class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n);
        
        prefix[0]=nums[0];
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        
        unordered_map<int,int> m;
        
        int i=0;
        int j=0;
        
        int ans=nums[0];
        
        for(;i<n;i++){
            
            m[nums[i]]++;
            
            while(m[nums[i]]>1){
                
                m[nums[j]]--;
                j++;
                
                
            }
            
            
            int curr;
            
            if(j==0){
                
                curr=prefix[i];
                
            }
            else{
                curr=prefix[i]-prefix[j-1];
            }
            
            ans=max(curr,ans);
            
        }
        
        return ans;
        
    }
};