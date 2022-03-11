class Solution {
public:
    int minimumDeletions(string s) {
        
        int n=s.size();
        vector<int> dp(n+1,0);
        int count=0;
        for(int i=0;i<n;i++){
            
            if(s[i]=='b')dp[i+1]=dp[i],count++;
            else{
                //We have now two choices 
                //either to remove that 'a' or remove all 'b' before it
                
                dp[i+1]=min(dp[i]+1,count);
            }
        }
        return dp[n];
        
    }
};