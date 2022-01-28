class WordDictionary {
    unordered_map<int,vector<string>> m;
    
    bool isTrue(string s,string word)
    {
   
        int n=s.size();
  
   for(int i=0;i<n;i++){
       
       if(word[i]=='.')continue;
       if(s[i]!=word[i])return false;
       
   }
        
        return true;
        
    }
    
public:
    WordDictionary() {
        
    }
    
    void addWord(string word) {
      m[word.size()].push_back(word);  
    }
    
    bool search(string word) {
        
        for(auto s:m[word.size()]){
            if(isTrue(s,word))return true;
        }
        
        return false;
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */