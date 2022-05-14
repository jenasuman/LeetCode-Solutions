class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int start,int k,int n,vector<int>& res){
        
        if(res.size()==k){
            if(n==0)ans.push_back(res);
            return;
        }
        
        for(int i=start;i<=9;i++){
            if(i<=n){
                res.push_back(i);
                solve(i+1,k,n-i,res);
                res.pop_back();
            }
        }
        
        
        
    }
    
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> res;
        
        solve(1,k,n,res);
        
        return ans;
        
        
        
    }
};