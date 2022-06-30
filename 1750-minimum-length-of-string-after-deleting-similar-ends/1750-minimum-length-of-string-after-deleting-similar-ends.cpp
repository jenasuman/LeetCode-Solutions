class Solution {
public:
    int minimumLength(string s) {
        
        int n=s.size();
        int i=0;
        int j=n-1;
        
        while(s[i]==s[j] && i<j){
            
            while(j-1>i){
                if(s[j]==s[j-1])j--;
                else break;
            }
            while(i+1<j){
                if(s[i]==s[i+1])i++;
                else break;
            }
            
            i++;
            j--;
            
            
        }
        
        return j<i?0:j-i+1;
        
        
    }
};