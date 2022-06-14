class Solution {
    int n;
    int m;
    int dp[502][502];
    int f(int i,int j,string& word1,string& word2){
        
        if(j<0){
            
            return i+1;
            
        }
        if(i<0 && j>=0){
            return j+1;
        }
        if(i<0){
            
            return INT_MAX-1;
            
        }
        if(dp[i][j]!=-1)return dp[i][j];
        if(word1[i]==word2[j]){
            
            return dp[i][j]=f(i-1,j-1,word1,word2);
        }
        
        int replaceCase=1+f(i-1,j-1,word1,word2);
        int deleteCase=1+f(i-1,j,word1,word2);
        int insertCase=1+f(i,j-1,word1,word2);
        
        
        return dp[i][j]=min({replaceCase,deleteCase,insertCase});
    }
public:
    int minDistance(string word1, string word2) {
     
     n=word1.size();
     m=word2.size();
     
     int i=n-1;
     int j=m-1;
     memset(dp,-1,sizeof(dp));   
       
    return f(i,j,word1,word2);    
         
         
        
        
        
    }
};