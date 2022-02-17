class Solution {
public:
   vector<vector<int>> ans;
    void calc(int x,vector<int> candidates,int target,vector<int> &v){
        
        for(int i=x;i<candidates.size();i++){
            
            v.push_back(candidates[i]);
            
            if(target-candidates[i]>=0){
            if(target-candidates[i]==0){
                ans.push_back(v);
               
            }
            else    
            calc(i,candidates,target-candidates[i],v);
            }
            
            v.pop_back();
        
        }
        
        
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
    
        
        vector<int> v;
        
        calc(0,candidates,target,v);
        
        return ans;
        
    }
};