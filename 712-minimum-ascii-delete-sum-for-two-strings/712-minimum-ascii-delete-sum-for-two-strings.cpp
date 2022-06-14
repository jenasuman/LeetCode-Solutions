class Solution {
    int dp[1001][1001];
    int prefix1[1001];
    int prefix2[1001];
    int f(int i,int j,string& s1,string& s2){
        
        if(i<0 && j>=0){
            return prefix2[j];
        }
        if(i>=0 && j<0){
            return prefix1[i];
        }
        if(i<0 && j<0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
         if(s1[i]==s2[j]){
            return dp[i][j]=f(i-1,j-1,s1,s2);
        }
        
        int choice1=s1[i]+f(i-1,j,s1,s2);
        int choice2=s2[j]+f(i,j-1,s1,s2);
        // cout<<choice1<<" "<<choice2<<"\n";
        return dp[i][j]=min(choice1,choice2);
        
        
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        
        int n=s1.size();
        int m=s2.size();

        
        memset(dp,-1,sizeof(dp));
        memset(prefix1,0,sizeof(prefix1));
        memset(prefix2,0,sizeof(prefix2));
        prefix1[0]=s1[0];
        // cout<<prefix1[0];
        prefix2[0]=s2[0];
        for(int i=1;i<n;i++){
            prefix1[i]=prefix1[i-1]+s1[i];
            // cout<<prefix1[i]<<" ";
        }
        // cout<<"\n";
        for(int i=1;i<m;i++){
              prefix2[i]=prefix2[i-1]+s2[i];
        }
        int i=n-1;
        int j=m-1;
        return f(i,j,s1,s2);
        
    }
};