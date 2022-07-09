class Solution {
public:
    string longestPrefix(string s) {
          
        int n=s.size();
        
        vector<int> LPS(n);
        
        LPS[0]=0;
        
        int j=0;
        int i=1;
        
        while(i<n){
            
            if(s[i]==s[j]){
                LPS[i]=j+1;
                j++;
                i++;
            }
            else{
                if(j!=0)j=LPS[j-1];
                else i++;
            }
            
        }
        
        
        return s.substr(0,j);
        
        
    }
};