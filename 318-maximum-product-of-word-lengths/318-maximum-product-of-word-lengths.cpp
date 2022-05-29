class Solution {
public:
    int maxProduct(vector<string>& words) {
  
         int n=words.size();
         int ans=0;
         
        vector<vector<int>> v(n,vector<int>(26,0));
        
        for(int i=0;i<n;i++){
            
            for(auto c:words[i]){
                
                v[i][c-'a']++;
                
            }
            
            
        }
        
        
        
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){
                
                bool flag=true;
                
                for(int k=0;k<26;k++){
                    
                    if(v[i][k]!=0 && v[j][k]!=0){
                        
                        flag=false;
                    }
                    
                    
                    
                }
                
                if(flag){
                    int temp=words[i].size()*words[j].size();
                    ans=max(ans,temp);
                }    
                
            }
        }
            
        
        return ans;
    }
};