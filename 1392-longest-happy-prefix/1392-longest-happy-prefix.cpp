class Solution {
public:
    string longestPrefix(string s) {
          
        int n=s.size();
        
        vector<int> lps(n,0);
        
        
        int i=1;
        int j=0;
        
        while(i<n){
            
            if(s[i]==s[j]){
                j++;
                lps[i]=j;
                i++;
            }
            else{
                
                if(j!=0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
                
                
                
            }
            
            
            
            
        }

        return s.substr(0,lps.back());
        
    }
};