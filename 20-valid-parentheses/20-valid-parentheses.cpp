class Solution {
public:
    bool isValid(string st) {
        stack<char> s;
        
        for(auto c:st){
            if(c=='(' || c=='{' || c=='[')s.push(c);
            else{
                if(s.empty())return false;
                if(c==']')
                {
                    if(s.top()=='[')s.pop();
                    else return false;
                }
                else if(c=='}')
                {
                    if(s.top()=='{')s.pop();
                    else return false;
                }
                else if(c==')')
                {
                    if(s.top()=='(')s.pop();
                    else return false;
                }
            }
        }
        
        if(s.size()>0)return false;
        return true;
    }
};