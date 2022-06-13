class Solution {
    int dp[501][501];
    int LCS(int i,int j,string& w1,string& w2){
        
        if(i<0 || j<0)return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        
        
        if(w1[i]==w2[j]){
            dp[i][j]=1+LCS(i-1,j-1,w1,w2);
        }
        else{
            dp[i][j]=max(LCS(i-1,j,w1,w2),LCS(i,j-1,w1,w2));
        }
        
        return dp[i][j];
        
        
    }
public:
    int minDistance(string word1, string word2) {
        
        int n=word1.size();
        int m=word2.size();
        memset(dp,-1,sizeof(dp));
        int ans=n+m-2*LCS(n-1,m-1,word1,word2);
        
        return ans;
        
        
    }
};