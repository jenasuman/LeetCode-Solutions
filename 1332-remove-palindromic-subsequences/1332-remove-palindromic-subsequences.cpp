class Solution {
    bool isPallindrome(string& s)
    {
        
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        
        return true;
        
    }   
public:
    
    int removePalindromeSub(string s) {
        if(isPallindrome(s)){
            return 1;
        }
        
        return 2;
        
    }
};