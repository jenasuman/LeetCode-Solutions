class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        
        string word;
        
        stringstream iss(s);
        
        while(iss>>word){
            v.push_back(word);
        }
        
        set<string> S;
        
        unordered_map<char,string> m;
        
        int n=pattern.size();
        
        int p=v.size();
        
        if(n!=p)return false;
        
        for(int i=0;i<n;i++){
            
            if(m.find(pattern[i])!=m.end()){
                if(m[pattern[i]]!=v[i])return false;
            }
            else{
                if(S.count(v[i])>0){
                    return false;
                }
                
                m[pattern[i]]=v[i];
                S.insert(v[i]);
                
                
            }
        }
        
        
        
        return true;
        
    }
};