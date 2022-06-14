class Solution {
    // int n;
    // int m;
    // int dp[502][502];
//     int f(int i,int j,string& word1,string& word2){
        
//         if(j<0){
            
//             return i+1;
            
//         }
//         if(i<0 && j>=0){
//             return j+1;
//         }
//         if(i<0){
            
//             return INT_MAX-1;
            
//         }
//         if(dp[i][j]!=-1)return dp[i][j];
//         if(word1[i]==word2[j]){
            
//             return dp[i][j]=f(i-1,j-1,word1,word2);
//         }
        
//         int replaceCase=1+f(i-1,j-1,word1,word2);
//         int deleteCase=1+f(i-1,j,word1,word2);
//         int insertCase=1+f(i,j-1,word1,word2);
        
        
//         return dp[i][j]=min({replaceCase,deleteCase,insertCase});
//     }
public:
    int minDistance(string word1, string word2) {
     
     int n=word1.size();
     int m=word2.size();
     
     // int i=n-1;
     // int j=m-1;
     // memset(dp,-1,sizeof(dp));  
     
     // vector<vector<int>> dp(n+1,vector<int>(m+1,0));
      vector<int> dp(m+1,0);  
        
     dp[0]=0;
        
//      for(int i=1;i<=n;i++){
         
//          dp[i][0]=i;
         
//      }   
     for(int i=1;i<=m;i++){
         
         dp[i]=i;
         
     }   
     
    for(int i=1;i<=n;i++){
        vector<int> temp(m+1,0);
        temp[0]=i;
        for(int j=1;j<=m;j++){
            
         if(word1[i-1]==word2[j-1]){
            
             temp[j]=dp[j-1];
    
        }
        else{
        int replaceCase=1+dp[j-1];
        int deleteCase=1+dp[j];
        int insertCase=1+temp[j-1];
        temp[j]=min({replaceCase,deleteCase,insertCase}); 
        }    
            
            
        }
        dp=temp;
    }    
        
       
    return dp[m];   
         
         
        
        
        
    }
};