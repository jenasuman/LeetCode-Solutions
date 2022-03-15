class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        int count=0;
        stack<int> st;
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='('){
                st.push(i);
            }
            if(s[i]==')'){
                if(!st.empty() && s[st.top()]=='(')st.pop();
                else st.push(i);
            }
            
            
        }
        // set<int> m;
        
        while(!st.empty()){
            s[st.top()]='#';
            st.pop();
        }
        
        string ans="";
        
        for(int i=0;i<n;i++){
            
            if(s[i]!='#')ans.push_back(s[i]);
            
        }
        return ans;
    }
};