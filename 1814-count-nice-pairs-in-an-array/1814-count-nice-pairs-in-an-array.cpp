class Solution {
public:
    int countNicePairs(vector<int>& nums) {
         
        
        int n=nums.size();
        // vector<int> v(n);
        
        for(int i=0;i<n;i++){
        
            int currNumber=nums[i];
            int newNumber=0;
            while(currNumber!=0){
                
                int remainder=(currNumber%10);
                // cout<<remainder<<" ";
                newNumber=newNumber*10+remainder;
                
                currNumber/=10;
                
                
            }
            // cout<<newNumber<<" ";
            nums[i]-=newNumber;
            
        }
        
        unordered_map<int,int> m;
        int mod=1e9+7;
        
        long long int ans=0;
        
        for(int i=0;i<n;i++){
            
            if(m.find(nums[i])!=m.end()){
                ans=(ans+m[nums[i]])%mod;
            }
            
            m[nums[i]]++;
        }
        
        return ans%mod;
        
        
    }
};