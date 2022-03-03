class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=t.size()-1;
        int i=s.size()-1;
        
        if(i>j)return false;
        
        while(j>=0 && i>=0){
            if(s[i]==t[j]){
                i--;
            }
            j--;
            
        }
        
        if(i<0)return true;
        return false;
    }
};