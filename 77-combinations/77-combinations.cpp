class Solution {
public:
    vector<vector<int>> ans;
    
    void solve(int index,int n,int k,vector<int>& temp){
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }
        
        for(int i=index;i<=n;i++){
            temp.push_back(i);
            solve(i+1,n,k,temp);
            temp.pop_back();
        }
        
        return;
        
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        solve(1,n,k,temp);
        
        return ans;
            
    }
};