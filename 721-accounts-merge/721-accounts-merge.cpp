class Solution {
    unordered_map<string,vector<string>> G;
    unordered_set<string> seen;
    vector<vector<string>> ans;
public:
    void dfs(string& email){
        
        seen.insert(email);
        
        ans.back().push_back(email);
        
        for(auto& s:G[email]){
            
            if(!seen.count(s)){
                dfs(s);
            }
            
            
        }
        
        
        
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n=accounts.size();
        
        for(auto& acc:accounts){
            
            for(int i=2;i<size(acc);i++){
                
                G[acc[i]].push_back(acc[i-1]);
                G[acc[i-1]].push_back(acc[i]);
                
            }
            
            
            
            
        }
        
        for(auto& acc:accounts){
            
            if(!seen.count(acc[1]))
            {
                
                ans.push_back({acc[0]});
                
                dfs(acc[1]);
                
                sort(begin(ans.back())+1,end(ans.back()));
                
            }
            
            
            
        }
        
        return ans;
    }
};