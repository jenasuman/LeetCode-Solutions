class CombinationIterator {
     vector<string> v;
    void solve(int index,int n,string& s,int l,string& temp){
        
        if(temp.size()==l){
            v.push_back(temp);
            return;
        }
        
        for(int i=index;i<n;i++){
            
            temp.push_back(s[i]);
            solve(i+1,n,s,l,temp);
            temp.pop_back();
            
            
            
        }
        
        
    }
    int m;
    int curr;
public:
    CombinationIterator(string s, int l) {
       
        int n=s.size();
        string temp="";
        solve(0,n,s,l,temp);
        m=v.size();
        curr=0;
        
        
    }
    
    string next() {
        if(curr>=m)return "";
        string ans=v[curr];
        curr++;
        return ans;
    }
    
    bool hasNext() {
        return curr<m;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */