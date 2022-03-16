class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        int i=0;
        int j=0;
        
        int n=pushed.size();
        
        stack<int> s;
        // s.push(pushed[i++]);
        while(i<n){
            
            s.push(pushed[i++]);
            
            while(!s.empty() && s.top()==popped[j]){
                s.pop();
                j++;
            }
            
            
        }
        
        return s.empty();
        
        // 1 2 3 4       
        
    }
};