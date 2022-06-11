class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& p, long long success) {
        
        sort(p.begin(),p.end());
        
        int n=s.size();
        int m=p.size();
        long double su=success;
        vector<int> ans;
        for(int i=0;i<n;i++){
            
            long long  k=ceil(su/s[i]);
            
            int index=lower_bound(p.begin(),p.end(),k)-p.begin();
            
            ans.push_back((m-index));
            
        }
        
        
        return ans;
        
    }
};