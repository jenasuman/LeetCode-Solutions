class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> m;
        
        int n=nums.size();
        
        int sum=0;
        
        int ans=0;
        int j=0;
        
        for(int i=0;i<n;i++){
            
            if(m.find(nums[i])!=m.end()){
                m[nums[i]]++;
                sum+=nums[i];
                while(m[nums[i]]>1){
                    m[nums[j]]--;//1 
                    sum-=nums[j];//10-4=6
                    j++;//1
                }
            }
            else{
                sum+=nums[i];//6+5=11+6=17
                m[nums[i]]++;
            }
            
            ans=max(ans,sum);
            
        }
        return ans;
    }
};