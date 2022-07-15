class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int n=nums.size();
//         for(int i=1;i<n;i++){
//             nums[i]+=nums[i-1];
//         }
        
//         if(nums[n-1]<target)return 0;
        
//         int ans=n;
//         // O(nlog(n))
//         for(int i=0;i<n;i++){
            
//             if(nums[i]<target){
//                 continue;
//             }
            
//             int r=nums[i]-target;
            
//             int index=lower_bound(begin(nums),begin(nums)+i,r)-begin(nums);

//             if(index==i){
//                 ans=min(ans,i-index+1);
//             }
//             if(index!=0){
//                 if(nums[index]==r){
//                     ans=min(ans,i-index);
//                 }
//                 else{
//                     ans=min(ans,i-index+1);
//                 }
//             }
//             if(index==0){
                
//                 if(nums[index]==r){
//                   ans=min(ans,i-index);
//                 }
//                 else ans=min(ans,i+1);
                
                
//             }
               
            
//         }
        
//         return ans;
        
        //Sliding Window
        
        int i=0;
        int j=0;
        
        int sum=0;
        
        int ans=INT_MAX;
        
        for(;i<n;i++){
            
            sum+=nums[i];
            
            while(sum>=target && j<=i){
                
                ans=min(ans,i-j+1);
                sum-=nums[j];
                j++;
                
            }
            
            
            
        }
        
        return ans==INT_MAX?0:ans;
        
        
        
    }
};