class Solution {
    int dp[1001][1001];
    int f(int i,int j,string& s1,string& s2){
        
        if(i<0 || j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(s1[i]==s2[j]){
           dp[i][j]=1+f(i-1,j-1,s1,s2);
        }
        else{
            
            dp[i][j]=max(f(i-1,j,s1,s2),f(i,j-1,s1,s2));
        }
        
        return dp[i][j];
    }
public:
    int longestPalindromeSubseq(string s) {
        memset(dp,-1,sizeof(dp));
        string temp=s;
        reverse(begin(temp),end(temp));
        int n=s.size();
        int i=n-1;
        int j=n-1;
        return f(i,j,s,temp);
        
    }
};