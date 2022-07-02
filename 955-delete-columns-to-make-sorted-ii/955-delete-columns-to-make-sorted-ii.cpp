class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        
        
        
        int n=strs.size();
        int m=strs[0].size();
        
        if(n==1){
            return 0;
        }
        int count=0;
        unordered_map<int,int> col;
        for(int k=0;k<m;k++){
        // bool flag=true;
        for(int i=1;i<n;i++){
            
            string s1=strs[i-1];
            string s2=strs[i];
            
            for(int j=0;j<m;j++){
                
                if(col.find(j)==col.end()){
                
                if(s1[j]==s2[j]){
                    continue;
                }
                if(s1[j]>s2[j]){
                     // flag=false;
                     col[j]++;
                }
                if(s1[j]<s2[j]){
                     break; 
                }    
                
                }
                
                
            }
            
            
            
            
             
         }   
            

        }    
            
            

        
        
        
        return col.size();
        
    }
};