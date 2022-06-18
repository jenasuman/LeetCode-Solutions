class WordFilter {
    unordered_map<string,int> myDict;
public:
    WordFilter(vector<string>& words) {
        
        int n=words.size();
        
        for(int i=0;i<n;i++){
            string s=words[i];
            
            int m=s.size();
            for(int j=0;j<m;j++){
                
                string prefix=s.substr(0,j+1);
                
                for(int k=m-1;k>=0;k--){
                    
                    string suffix=s.substr(k,m-k);
                    string key=prefix+"|"+suffix;
                    myDict[key]=i;
                    
                }
                
                
                
            }
        
        }
    }
    
    int f(string prefix, string suffix) {
       
        string key=prefix+"|"+suffix;
        
        return myDict.find(key)!=myDict.end()?myDict[key]:-1;
    
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */