class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        
        queue<string> q;
        
        q.push(start);
        unordered_set<string> b;
        
        for(auto s:bank)b.insert(s);
         
        int moves=0;
        char d[4]={'A','C','G','T'};
        unordered_set<string> s;
        s.insert(start);
        while(!q.empty()){
            
            int n=q.size();
            moves++;
            while(n--){
                
                auto st=q.front();
                q.pop();
                int m=st.size();
                for(int i=0;i<m;i++){
                    
                    for(int j=0;j<4;j++){
                        
                        char temp=st[i];
                        st[i]=d[j];
                        if(b.count(st)){
                            if(st==end)return moves;
                            if(s.count(st)==0)
                            q.push(st);
                            
                            s.insert(st);
                        }
                        st[i]=temp;
                        
                    }
                    
                    
                }
                
                
                
                
                
                
            }
            
            
            
            
            
            
        }
        
        return -1;
        
    }
};