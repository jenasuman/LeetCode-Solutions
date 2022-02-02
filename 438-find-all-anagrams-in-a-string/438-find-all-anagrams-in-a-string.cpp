class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();
        
        
        
        vector<int> ans;
        
        if(k>n)return ans;
        
        vector<int> a(26,0);
        vector<int> b(26,0);
        
        for(auto c:p){
            a[c-'a']++;
        }
        
        int j=0;
        
        for(int i=0;i<n;i++){
            
            b[s[i]-'a']++;
            
            if((i-j+1)==k){
                
                if(b==a){
                    ans.push_back(j);
                }
                
                b[s[j]-'a']--;
                j++;
                
                
                
                
            }
            
            
            
            
            
        }
        
        
        
        
        return ans;
        
    }
};