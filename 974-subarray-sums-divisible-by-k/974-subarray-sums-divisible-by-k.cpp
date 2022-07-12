class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
         
        int n=nums.size();
        
        if(n==0)return 0;
        
        unordered_map<int,int> m;
        
        m[0]=1;
        int sum=0;
        int ans=0;
        // cout<<(-8)%5;
        for(int i=0;i<n;i++){
            
             sum+=nums[i];
            
             int remainder=(sum)%k;
            
             if(remainder<0)remainder+=k;
            
             if(m.find(remainder)!=m.end())
                 ans+=m[remainder];
            
             m[remainder]++;
            
            
        }
        return ans;
        
    }
};