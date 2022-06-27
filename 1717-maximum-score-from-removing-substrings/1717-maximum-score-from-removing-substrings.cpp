class Solution {
    
    int countAB(string& s){
        
        stack<int> st;
        
        int n=s.size();
        int count=0;
        int j;
        for(int i=0;i<n;i++){
            
            
            if(s[i]=='b'){
                if(!st.empty()){
                    s[i]='#';
                    j=st.top();
                    s[j]='#';
                    count++;
                    st.pop();
                }
            }
            else if(s[i]=='#'){
                 continue;
            }
            else if(s[i]=='a'){
                
                st.push(i);
                
            }
            else{
                
                while(!st.empty()){
                    st.pop();
                }
                
            }
            
            
            
            
            
        }
        
        return count;
        
        
        
    }
        int countBA(string& s){
        
        stack<int> st;
        
        int n=s.size();
        int count=0;
        int j;
        for(int i=0;i<n;i++){
            
            
            if(s[i]=='a'){
                if(!st.empty()){
                    s[i]='#';
                    j=st.top();
                    s[j]='#';
                    st.pop();
                    count++;
                }
            }
            else if(s[i]=='#'){
                 continue;
            }
            else if(s[i]=='b'){
                
                st.push(i);
                
            }
            else{
                
                while(!st.empty()){
                    st.pop();
                }
                
            }
            
            
            
            
            
        }
        
        return count;
        
        
        
    }
    
public:
    int maximumGain(string s, int x, int y) {
        string temp1=s;
        string temp2=s;

        
        int ans1=0;
        int ans2=0;
        int u;
        int v;
        
        v=countAB(temp1);
        u=countBA(temp1);
        // cout<<u<<" "<<v<<"\n";
        ans1=x*v+y*u;

              u=countBA(temp2);
              v=countAB(temp2);
              // cout<<u<<" "<<v<<"\n"
              ans2=y*u+x*v;
           
             
        
          return max(ans1,ans2);
        
           
           
        
    }
};