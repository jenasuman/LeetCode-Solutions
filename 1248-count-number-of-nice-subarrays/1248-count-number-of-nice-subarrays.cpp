class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
         int n=nums.size();
         for(int i=0;i<n;i++){
             nums[i]=(nums[i]%2);
         }
         for(int i=1;i<n;i++)nums[i]+=nums[i-1];
         unordered_map<int,int> m;
         int ans=0;
         m[0]=1;
         for(int i=0;i<n;i++){
             
             if(m.find(nums[i]-k)!=m.end()){
                 ans+=m[nums[i]-k];
             }  
             
             m[nums[i]]++;
             
             
         }
        
        return ans;
         
    }
};