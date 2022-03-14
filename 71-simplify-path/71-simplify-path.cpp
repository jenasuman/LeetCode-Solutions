class Solution {
public:
    string simplifyPath(string path) {
         stack<string> s;
         
         int n=path.size();
         int i=0;
         while(i<n){
             
             if(path[i]=='/')i++;
             
             else{
                 
                 string word="";
                 
                 while(i<n && path[i]!='/')word.push_back(path[i++]);
                 
                 if(word==".."){
                     if(!s.empty())
                     s.pop();
                 }
                 else if(word=="."){
                     continue;
                 }
                 else s.push(word);
                 
                 
             }
             
             
         }
        
        stack<string> s1;
        
        while(!s.empty()){
            s1.push(s.top());
            s.pop();
            }
        
        string ans="";
        if(s1.empty())ans="/";
        
        while(!s1.empty()){
            ans+="/";
            ans+=s1.top();
            s1.pop();
        }
        
        return ans;
        
    }
};