class Solution {
public:
    int minimumDeletions(string s) {
        // int count_b=0;
        int n=s.size();
        // vector<int> v(n);
        // vector<int> v2(n);
        int count_b=0;
        for(int i=0;i<n;i++){
            if(s[i]=='b')count_b++;
                
        }
        int count_a=0;
        int ans=INT_MAX;
        
        for(int i=n-1;i>=0;i--){
            if(s[i]=='b')count_b--;
            ans=min(ans,count_a+count_b);
            if(s[i]=='a')count_a++;
            
            
        }
        
        return ans;
        
    }
};