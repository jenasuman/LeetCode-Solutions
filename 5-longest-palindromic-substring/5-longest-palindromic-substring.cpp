class Solution {


public:
    string longestPalindrome(string s) {
        string temp;
        temp=s;
        reverse(begin(temp),end(temp));
        
        int n=s.size();
        string ans="";
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        int res=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                
                if(s[i-1]==temp[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    
                    if(dp[i][j]>res){
                        string currAns=s.substr(i-dp[i][j],dp[i][j]);
                        string currReverse=currAns;
                        reverse(currReverse.begin(),currReverse.end());
                        if(currReverse==currAns ){
                            ans=currAns;
                            res=currAns.size();
                          }
                    }
                    
                    
                }
                else{
                    
                    dp[i][j]=0;

                    
                    
                }
                

                
                
            }
        }
        // cout<<res<<"\n";
        return ans;
        
        
    }
};