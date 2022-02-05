class Solution {
public:
    int f(vector<int>& nums,int a,int b){
        
        int n=nums.size();
        vector<int> maxi(n,-1);
        
        int sum=0;
        
        for(int i=0;i<a-1;i++){
            sum+=nums[i];
        }
        
        for(int i=a-1;i<n;i++){
            
            sum+=nums[i];
            
            if(i-1>=0){
                maxi[i]=max(maxi[i-1],sum);
            }
            else maxi[i]=sum;
            
            sum-=nums[i-(a-1)];
            
            
        }
        sum=0;
        
        for(int i=n-1;i>n-b;i--){
            
            sum+=nums[i];
            
        }
        
        int suff=-1;
        int ans=0;
        for(int i=n-b;i>0;i--){
            
            sum+=nums[i];
            
            suff=max(suff,sum);
            
            if(maxi[i-1]!=-1){
                ans=max(ans,maxi[i-1]+suff);
            }
            
            sum-=nums[i+(b-1)];
            
            
        }
        
        
        
        return ans;
        
        
        
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int L, int M) {
        
        return max(f(nums,L,M),f(nums,M,L));
        
    }
};