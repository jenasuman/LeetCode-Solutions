class Solution {
public:
    string interpret(string s) {
       string ans="";
       
      int i=0;
      int n=s.size();
      
      while(i<n){
          
          if(s[i]=='G'){
              ans.push_back('G');
              i++;
         }
          else if(s[i]=='(' && s[i+1]==')'){
               i+=2;
              ans.push_back('o');
          }
          else if(s[i]=='(' && s[i+1]=='a'){
              i+=4;
              ans.push_back('a');
              ans.push_back('l');
          }
          
          
      }  
      
    return ans;
        
    }
};