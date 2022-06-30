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
        
        vector<int> dp(n+1,1);
        
        for(int i=1;i<=n;i++){
            
            dp[i]+=dp[i-1];
            string temp="";
            // dp[i]++;
            temp.push_back(s[i-1]);
            for(int j=i;j<n;j++){
                
                temp.push_back(s[j]);
                
                if(isPalindrone(temp)){
                    dp[i]++;
                }
                
             }
            
            
            
            
        }
        
        return dp[n-1];
        
    }
};