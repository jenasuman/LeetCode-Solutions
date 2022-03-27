class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        vector<pair<int,int>> v;
        
        int n=mat.size();
        int m=mat[0].size();
        
        for(int i=0;i<n;i++){
            int count=0;
            
            for(int j=0;j<m;j++){
                count+=mat[i][j];
            }
            
            v.push_back({count,i});
            
        }
        
        sort(v.begin(),v.end());
        vector<int> ans;
        
        int i=0;
        while(k--){
            ans.push_back(v[i].second);
            i++;
        }
        
        return ans;
        
    }
};