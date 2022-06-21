class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        vector<vector<int>>v(n,vector<int>(26,0));
        v[0][s[0]-'a']++;
        for(int i=1;i<n;i++){
            
            v[i]=v[i-1];
            
            v[i][s[i]-'a']++;
            
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            
            for(int j=i;j<n;j++){
                
                int ma=0;
                int mi=502;
                
                for(int k=0;k<26;k++){
                    
                    ma=max(v[j][k],ma);
                    if(v[j][k]!=0)mi=min(v[j][k],mi);
                    
                }
                // cout<<ma<<" "<<mi<<"\n";
                ans+=(ma-mi);
                
            }
            
            for(int j=0;j<n;j++){
                v[j][s[i]-'a']--;
            }
            
            
            
        }
            
        
        
        return ans;
        
    }
};