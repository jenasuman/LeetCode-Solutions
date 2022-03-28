class Solution {
public:
    typedef long long int ll;
    long long int solve(vector<int>& nums,int right){
        
        ll temp_size=0;
        ll ans=0;
        int n=nums.size();
        
        
        for(int i=0;i<n;i++){
            
            if(nums[i]<=right){
                temp_size++;
            }
            else{
                ans+=(temp_size)*(temp_size+1)/2;
                temp_size=0;
            }
            
        }
        
        ans+=temp_size*(temp_size+1)/2;
        
        return ans;
        
        
        
        
        
        
    }
    
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
       
        return solve(nums,right)-solve(nums,left-1);
        
    }
};