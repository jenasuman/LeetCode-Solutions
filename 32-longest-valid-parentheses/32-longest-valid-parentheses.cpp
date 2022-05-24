class Solution {
public:
    int longestValidParentheses(string s) {
        
        stack<int> st;
        int n=s.size();
        if(n==0)return 0;
        // cout<<n;
        // st.push(-1);
        for(int i=0;i<n;i++){
            
            if(s[i]=='(')st.push(i);
            
            else{
                
                if(!st.empty()){
                    if(s[st.top()]=='(')st.pop();
                    else st.push(i);
                }
                else st.push(i);
            }
        }
        // cout<<413646384;
        if(st.empty())return n;
        else{
            
            int a=n;
            int b=0;
            // cout<<st.top();
            int ans=0;
            
            while(!st.empty()){
                
                b=st.top();
                // cout<<b;
                st.pop();
                // cout<<a-b-1;
                ans=max(ans,a-b-1);
                
                a=b;
                
                
            }
            // cout<<ans;
            ans=max(ans,a);
            // cout<<a;
            return ans;
            
            
        }
        
        return 0;
        
    }
};