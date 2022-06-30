using ll = long long int;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        
        int n=nums.size();
        
        if(n==1){
            return 0;
        }
        
        vector<ll> prefix(n);
        vector<ll> suffix(n);
          
        prefix[0]=nums[0];
        suffix[n-1]=nums[n-1];
        
        for(int i=1;i<n;i++){
            
            prefix[i]=prefix[i-1]+nums[i];
            
        }
        
        for(int i=n-2;i>=0;i--){
            
            suffix[i]=suffix[i+1]+nums[i];
            
        }
        ll ans=INT_MAX;
        for(int i=0;i<n;i++){
            
            ll left=((ll)(i+1)*(ll)(nums[i])-prefix[i]);
            ll right=(suffix[i]-(ll)(n-i)*(ll)(nums[i]));
            
            ll res=left+right;
            
            ans=min(res,ans);
            
            
            
        }
        
        return ans;
        
        
        
    }
};