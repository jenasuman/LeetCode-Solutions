class Solution {


public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int n=s.size();
        string res="";
        for(auto str:dictionary){
            
            int i=0;
            int j=0;
            int m=str.size();
            while(j<n && i<m){
                
                if(str[i]==s[j]){
                    i++;
                }
                j++;
                
                
            }
            
            if(i==m){
                if(res.size()<str.size()){
                    res=str;
                }
                else if(res.size()==str.size()){
                    if(res>str)
                    res=str;
                }
            }
            
            
        }
        
        
        return res;
    }
};