class Solution {
public:
    bool detectCapitalUse(string word) {
        
        string temp1="";
        string temp2="";
        
        int n=word.size();
        
        for(int i=0;i<n;i++)
        {
            char c=tolower(word[i]);
            temp1.push_back(c);
            c=toupper(word[i]);
            temp2.push_back(c);
            
        }        
        
        if(temp1==word || temp2==word)return true;
        
        temp1[0]=toupper(temp1[0]);
        
        if(temp1==word)return true;
        
        // cout<<temp2<<" "<<temp1<<" "<<word;
        return false;
        
        
    }
};