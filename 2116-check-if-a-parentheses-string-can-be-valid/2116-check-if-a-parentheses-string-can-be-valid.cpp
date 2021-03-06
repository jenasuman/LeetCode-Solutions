class Solution {
public:
    bool canBeValid(string s, string locked) {
        // cout<<s.size()<<"\n";
        if(s.size()%2!=0)return false;
        int lopen=0,free=0,lclose=0;
        for(int i=0;i<s.size();i++){
            if(locked[i]=='0') free++;
            else{
                if(s[i]=='(') lopen++;
                else 
                    lclose++;
            }
            // cout<<free<<"\n";
            if(lclose>free+lopen) return false;
        }
        
          lopen=0,free=0,lclose=0;
        for(int i=s.size()-1;i>=0;i--){
            if(locked[i]=='0') free++;
            else{
                if(s[i]=='(') lopen++;
                else 
                    lclose++;
            }
            if(lopen>free+lclose) return false;
        }
        return true;

    }
};