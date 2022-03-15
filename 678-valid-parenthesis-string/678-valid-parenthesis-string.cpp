class Solution {
public:
    bool checkValidString(string s) {
        stack<int> astrick;
        stack<int> open;
        
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(s[i]=='*')astrick.push(i);
            else if(s[i]=='(')open.push(i);
            else{
                if(!open.empty())open.pop();
                else if(!astrick.empty())astrick.pop();
                else{
                    return false;
                }
            }
        }
        
        while(!astrick.empty() && !open.empty()){
            if(astrick.top()<open.top())return false;
            astrick.pop();
            open.pop();
        }
        
        if(!open.empty())return false;
        
        return true;
        
    }
};