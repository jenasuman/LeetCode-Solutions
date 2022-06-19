class Solution {
      int dp[101];
      int f(int i,string& s){
          
          if(i==s.size()-1 && s[i]!='0')return 1;
          
          if(i==s.size())return 1;
          
          if(s[i]=='0')return 0;
          
          if(dp[i]!=-1)return dp[i];
          string t=s.substr(i,2);
          
          int case1=f(i+1,s);
          int case2=0;
          if(stoi(t)>9 && stoi(t)<=26){
              case2=f(i+2,s);
          }
          
          return dp[i]=case1+case2;
         

      } 
public:
        int numDecodings(string s) {
        //MCM type problem
        int i=0;

        memset(dp,-1,sizeof(dp));
        return f(i,s);
        
    }
};