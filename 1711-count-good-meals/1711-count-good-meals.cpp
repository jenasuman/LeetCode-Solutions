class Solution {
public:
    int countPairs(vector<int>& d) {
        unordered_map<int,int> m;
        int n=d.size();
        long long int ans=0;
        int mod=1e9+7;

      
        
        for(int i=0;i<n;i++){
            
        for(int j=0;j<=21;j++){
            int t=pow(2,j);
            
            if(m.find(t-d[i])!=m.end())ans=(ans+m[t-d[i]])%mod;
            
          }  
            
            m[d[i]]++;
    
            
        }
        
        return ans%mod;
    }
};