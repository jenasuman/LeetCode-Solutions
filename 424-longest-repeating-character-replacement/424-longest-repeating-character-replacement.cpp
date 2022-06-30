class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int n=s.size();
        
        vector<int> v(26,0);
        
        int ans=1;
        int j=0;
        int maxCount=0;
        for(int i=0;i<n;i++){
         
            v[s[i]-'A']++;
            
            maxCount=max(v[s[i]-'A'],maxCount);
            
            while((i-j-maxCount+1)>k){
                
                v[s[j]-'A']--;
                j++;
                for(int k=0;k<26;k++){
                    
                    maxCount=max(v[k],maxCount);
                    
                    
                }
                
                
                
                
                
            }
            
            ans=max(i-j+1,ans);

            
        }
        
        return ans;
        
        
    }
};