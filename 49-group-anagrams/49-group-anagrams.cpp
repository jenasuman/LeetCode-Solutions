class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        map<string,vector<string>> m;
        int n=strs.size();
        for(int i=0;i<n;i++){
            
            string temp=strs[i];
            sort(begin(temp),end(temp));
            m[temp].push_back(strs[i]);
            
         }
        
        vector<vector<string>> ans;
        
        for(auto v:m){
            ans.push_back(v.second);
        }
        
        return ans;
        
    }
};