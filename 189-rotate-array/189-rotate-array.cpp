class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> ans(n,0);
        
        if(k>=n){
            
            k=(k%n);
            
        }
        
        int i=n-1;
        int t=k;
        
        
        
        while(t && i>=0){
            
            ans[t-1]=nums[i];
            t--;
            i--;
         }
         t=k;
          
         for(int j=0;j<n-k;j++){
             ans[t]=nums[j];
             t++;
         }
        nums=ans;
    }
};