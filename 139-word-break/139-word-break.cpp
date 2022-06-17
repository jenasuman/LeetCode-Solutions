class Solution {
    unordered_map<string,int> m;
//     int dp[302][302];
    
//     bool f(int i,int j,string& s){
        
//         if(i>j){
//             return false;
//         }
//         if(dp[i][j]!=-1)return dp[i][j];
        
//         string currSubstring=s.substr(i,j-i+1);
        
//         if(m.find(currSubstring)!=m.end())return dp[i][j]=true;
        
//         for(int k=i;k<j;k++){
            
//             bool case1=f(i,k,s);
//             bool case2=f(k+1,j,s);
            
//             if(case1 and case2){
//                 return dp[i][j]=true;
//             }
            
//         }
        
//         return dp[i][j]=false;
        
//     }
    
    
public:
    bool wordBreak(string s, vector<string>& word) {
         
        int n=s.size();
        
        vector<bool> dp(n+1);
        
        dp[0]=true;
        
        for(int i=1;i<=n;i++){
            
            for(int j=0;j<i;j++){
                
                if(dp[j] && find(begin(word),end(word),s.substr(j,i-j))!=end(word)){
                    dp[i]=true;
                    break;
                }
                
                
                
                
            }
            
            
            
            
        }
        
        return dp[n];
        
        
    }
};