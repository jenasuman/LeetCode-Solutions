class Solution {
public:
   
    int minFlips(string s) {
        
        vector<vector<int>> v(2,vector<int>(2,0));
        int n=s.size();
        
        for(int i=0;i<n;i++){
            
            v[s[i]-'0'][i%2]++;
            
        }
        
        int ans=INT_MAX;
        
        ans=min(ans,v[1][0]+v[0][1]);
        ans=min(ans,v[1][1]+v[0][0]);
        
        for(int i=0;i<n;i++){
            
            v[s[i]-'0'][i%2]--;
            
            v[s[i]-'0'][(n+i)%2]++;
            
            ans=min({ans,v[0][0]+v[1][1],v[1][0]+v[0][1]});
            
            
            
            
            
        }
        
              
        
       return ans; 
        
        
    }
};