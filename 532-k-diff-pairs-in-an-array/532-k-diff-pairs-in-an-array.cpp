class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        
        map<int,int> m;
        int ans=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            
            int plus=nums[i]+k;
            int minus=nums[i]-k;
            
            if(k==0 && m[nums[i]]==1)ans++;
            
            else{
                
                if(m.find(nums[i])==m.end()){
                    
                    if(m.find(plus)!=m.end()){
                        ans++;
                    }
                    if(m.find(minus)!=m.end()){
                        ans++;
                    }
                    
                    
                    
                    
                }
                
                
                
            }
            m[nums[i]]++;
        }
        
        return ans;
        
    }
};