class Solution {
public:
    int minimumDeletions(string s) {
        int count_b=0;
        int n=s.size();
        vector<int> v(n);
        // vector<int> v2(n);
        int count=0;
        for(int i=0;i<n;i++){
            v[i]=count;
            if(s[i]=='b')count++;
                
        }
        count=0;
        int ans=INT_MAX;
        
        for(int i=n-1;i>=0;i--){
            
            ans=min(ans,count+v[i]);
            if(s[i]=='a')count++;
            
            
        }
        
        return ans;
        
    }
};