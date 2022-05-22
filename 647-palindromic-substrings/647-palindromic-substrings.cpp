class Solution {
public:
    bool isPalindrone(string s){
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int countSubstrings(string s) {
        
        int n=s.size();
        
        vector<int> dp(n,1);
        
        int ans=0;
        
        for(int i=1;i<n;i++){
            dp[i]+=dp[i-1];
            for(int j=i-1;j>=0;j--){
                
                string t=s.substr(j,i-j+1);
                if(isPalindrone(t)){
                    dp[i]+=1;
                }
                
            }
            
      
        }
        
        return dp[n-1];
        
    }
};