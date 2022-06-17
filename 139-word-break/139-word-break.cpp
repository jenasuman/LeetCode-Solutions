class Solution {
    unordered_map<string,int> m;
    int dp[302][302];
    
    bool f(int i,int j,string& s){
        
        if(i>j){
            return false;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        string currSubstring=s.substr(i,j-i+1);
        
        if(m.find(currSubstring)!=m.end())return dp[i][j]=true;
        
        for(int k=i;k<j;k++){
            
            bool case1=f(i,k,s);
            bool case2=f(k+1,j,s);
            
            if(case1 and case2){
                return dp[i][j]=true;
            }
            
        }
        
        return dp[i][j]=false;
        
    }
    
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        m.clear(); 
        
        for(auto w:wordDict){
              m[w]++;
        }
        int i=0;
        int j=s.size()-1;
        memset(dp,-1,sizeof(dp));
        return f(i,j,s);
        
        
        
    }
};