class Solution {
public:
    int removeDuplicates(vector<int>& s) {
        
        int n=s.size();
        
        // int s;
        int count=1;
        int j=-1;
        
        for(int i=1;i<n;i++){
            if(s[i-1]!=s[i]){
                count=1;
            }
            else {
               count++;
            }
            
            if(count==3 && j==-1){
                j=i;
            }
            
            if(j!=-1 && count<=2){
                s[j]=s[i];
                j++;
            }  
            
            
        }
        
        
        return j!=-1?j:n;
    }
};