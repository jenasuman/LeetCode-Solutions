class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        
        int n=nums.size();
        
        int rem=0;
        
        for(auto i:nums){
            rem=(rem+i)%p;
        }
        
        if(rem==0)return 0;
        
        int ans=n;
        
        map<int,int> m;
        m[0]=-1;
        int prefix=0;
        
        for(int i=0;i<n;i++){
            
            prefix=(prefix+nums[i])%p;
        
            int key=(prefix-rem)%p;
            
            if(key<0)key+=p;
            
            if(m.count(key)){
                ans=min(ans,i-m[key]);
            }
            m[prefix]=i;
        }
        
        return ans==n?-1:ans;
        
        
        
    }
};