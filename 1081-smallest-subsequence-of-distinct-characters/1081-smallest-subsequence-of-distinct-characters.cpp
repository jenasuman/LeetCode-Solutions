class Solution {
public:
    string smallestSubsequence(string s) {
        
        vector<int> v(26,-1);
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            
            
            v[s[i]-'a']=i;
            
            
        }
        
        string ans="";
        // int prev=-1;
        vector<int> vis(26,0);
        
        for(int i=0;i<n;i++){
            

            
           if(vis[s[i]-'a']==0)
           {
               
               while(ans.size()>0 && v[ans.back()-'a']>i && ans.back()>s[i]){
                   vis[ans.back()-'a']=0;
                   ans.pop_back();
                   
               }
               
               
               ans.push_back(s[i]);
               vis[s[i]-'a']=1;
               
               // cout<<ans<<"\n";
               
           }
            
            
            
            
            
        }
        
        return ans;
        
        
        
        
    }
};