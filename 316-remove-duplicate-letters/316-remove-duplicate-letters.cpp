class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> dict(26,0);
        vector<int> vis(26,0);
        
        for(auto c:s){
            dict[c-'a']++;
        }
        string ans="";
        int n=s.size();
        for(int i=0;i<n;i++){
               dict[s[i]-'a']--;
            if(vis[s[i]-'a']==1)continue;
            
            while(!ans.empty() && ans.back()>s[i] && dict[ans.back()-'a']>0){
                
                vis[ans.back()-'a']=0;
                ans.pop_back();
                
            }
            
            ans.push_back(s[i]);
         
            vis[s[i]-'a']=1;
            
            
        }
        
        return ans;
        
    }
};