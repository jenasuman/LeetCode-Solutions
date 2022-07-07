class Solution {
public:
    int dp[101][101];
    bool f(int i,int j,int k,string& s1,string& s2,string& s3){
        
        if(k<0 && i<0 && j<0){
            return true;
        }
        if(i<0 && j<0){
            return false;
        }
        if(i<0){
            
            string temp1=s3.substr(0,k+1);
            string temp2=s2.substr(0,j+1);
            return temp1==temp2;
            
        }
        if(j<0){
            
            string temp1=s3.substr(0,k+1);
            string temp2=s1.substr(0,i+1);
            return temp1==temp2;
            
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            
            return dp[i][j]=f(i-1,j,k-1,s1,s2,s3)||f(i,j-1,k-1,s1,s2,s3);
            
        }
        else if(s1[i]==s3[k]){
            
            return dp[i][j]=f(i-1,j,k-1,s1,s2,s3);
            
        }
        else if(s2[j]==s3[k]){
            
            return dp[i][j]=f(i,j-1,k-1,s1,s2,s3);
            
        }
        
        
        return dp[i][j]=false;
        
        
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        
        int n=s1.size();
        int m=s2.size();
        int l=s3.size();
        
        if(l!=n+m)return false;
        
        int i=s1.size()-1;
        int j=s2.size()-1;
        int k=s3.size()-1;
        
        
        memset(dp,-1,sizeof(dp));
        return f(i,j,k,s1,s2,s3);
        
        
        
        
        
    }
};