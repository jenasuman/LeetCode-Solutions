class Solution {
public:
    int calculate(string s) {
        
        stack<pair<int,int>> st;
        
        int n=s.size();
        
        long long int sum=0;
        
        int sign=1;
        
        for(int i=0;i<n;i++){
            
            char ch=s[i];
            
            if(isdigit(ch)){
                
                long long int currNumber=0;
                
                while(i<n and isdigit(s[i])){
                    
                    currNumber=currNumber*10+s[i]-'0';
                    i++;
                }
                
                
                i--;
                
                sum+=(sign*currNumber);
                
                sign=1;
                
            }
            else if(ch=='('){
                
                st.push({sum,sign});
                
                sum=0;
                sign=1;
                
                
            }
            
            else if(ch==')'){
                
                sum=st.top().first+(st.top().second*sum);
                
                st.pop();
                
            }
            else if(ch=='-'){
                
                sign*=-1;
                
                
            }
            
            
            
            
            
            
        }
        
        return sum;
        
    }
};