class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp(nums);
        
        // for(auto i:temp)cout<<i<<" ";
        
        int firstDiff=-1;
        int lastDiff=-1;
        
        sort(temp.begin(),temp.end());
        
        int n=temp.size();
        
        for(int i=0;i<n;i++){
            
            if(nums[i]!=temp[i]){
                if(firstDiff==-1){
                    firstDiff=i;
                    lastDiff=i;
                }
                else lastDiff=i;
            }
            
            
            
        }
        
        if(firstDiff==-1)return 0;
        
        
        
        return lastDiff-firstDiff+1;
        
        
        
    }
};