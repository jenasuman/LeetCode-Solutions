class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        
        sort(beans.begin(),beans.end());
        int n=beans.size();
        
        if(n==0)return 0;
        
        if(beans[0]==beans[n-1]){
            return 0;
        }
        
        vector<long long> prefix(n);
        
        prefix[0]=0;
        
        for(int i=1;i<n;i++){
            prefix[i]=beans[i-1]+prefix[i-1];
        }
        
        vector<long long int> suffix(n);
        
        suffix[n-1]=0;
        
        for(int i=n-2;i>=0;i--){
            
            suffix[i]=suffix[i+1]+beans[i+1];
            
        }
        
        long long  ans=1e13;
        
        for(long long  i=0;i<n;i++){
            long long  t=(long long)(n-i-1)*(long long)(beans[i]);
            long long currAns=prefix[i]+(suffix[i]-(t));
            
            ans=min(currAns,ans);
            
            
        }
        
        return ans;
        
    }
};