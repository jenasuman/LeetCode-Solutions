class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<int> s;
        
        for(auto c:tokens){
            
            if(c=="+"){
                
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                    
                a+=b;
                
                s.push(a);
                
            }
            else if(c=="-"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                    
                b-=a;
                
                s.push(b);
            }
            else if(c=="*"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                    
                a*=b;
                
                s.push(a);
            }
            else if(c=="/"){
                int a=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                
                if(a!=0)
                {b/=a;
                
                s.push(b);
                }
            }
            else{
                int j=0;
                bool flag=true;
                // cout<<c<<"\n";
                if(c[0]=='-'){
                    flag=false;
                    j++;
                }
                int num=0;
                
                for(;j<c.size();j++){
                    num=(num)*10+(c[j]-'0');
                }
                
                // cout<<num<<"\n";
                if(!flag)num*=(-1);
                s.push(num);
            }
            
            
        }
        
        return s.top();
        
        
    }
};