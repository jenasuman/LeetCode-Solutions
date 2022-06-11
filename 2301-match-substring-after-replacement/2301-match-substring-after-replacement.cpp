class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        
        unordered_map<char,unordered_set<char>> m;
        int n=s.size();
        int k=sub.size();
        
        for(auto v:mappings){
            m[v[0]].insert(v[1]);
        }
        
        for(int i=0;i<=n-k;i++){
            
            bool flag=true;
            
            for(int j=0;j<k;j++){
                
                char x=s[i+j];
                char y=sub[j];
                
                if(x==y || m[y].find(x)!=m[y].end()){
                    continue;
                }
                else 
                {flag=false;
                 break;
                }
                
                
                
            }
            
            if(flag)return true;
            
            
        }
        
        return false;
        
        
    }
};