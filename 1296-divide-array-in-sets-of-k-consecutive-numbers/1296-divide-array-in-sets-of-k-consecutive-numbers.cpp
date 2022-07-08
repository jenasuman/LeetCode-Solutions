class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        int n=nums.size();
        unordered_map<int,int> m;
        // for(int i=0;i<n;i++){
        //     cout<<nums[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            
              if(m.find(nums[i])==m.end())continue;
              
              int currRequired=nums[i]+1;
              // cout<<nums[i]<<" ";
              for(int j=2;j<=k;j++){
                  
                 if(m.find(currRequired)==m.end()){
                     
                     return false;
                 }
                  m[currRequired]--;
                  // cout<<currRequired<<" ";
                  if(m[currRequired]==0)m.erase(currRequired);
                  currRequired++;
                  
                  
              }
               
              m[nums[i]]--;
              if(m[nums[i]]==0)m.erase(nums[i]);
              // cout<<endl;
            
        }
        
        return true;
    }
};