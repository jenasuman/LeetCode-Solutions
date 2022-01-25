class Solution {
public:
    vector<int> parent;
    int find(int x){
        
        return parent[x]==x?x:find(parent[x]);
        
    }
    bool equationsPossible(vector<string>& equations) {
        
        parent.resize(26,0);
        
        for(int i=0;i<26;i++)
            parent[i]=i;
        
        int n=equations.size();
        for(int i=0;i<n;i++){
            
            if(equations[i][1]=='='){
                
                int x=find(equations[i][0]-'a');
                int y=find(equations[i][3]-'a');
                
                if(x!=y){
                    parent[x]=y;
                }
                
                
                
                
                
                
                
            }
            
            
            
            
            
            
        }
        
        for(int i=0;i<n;i++){
            
            if(equations[i][1]=='!'){
                
                int x=find(equations[i][0]-'a');
                int y=find(equations[i][3]-'a');
                
                if(x==y){
                    return false;
                }
                
                
                
                
                
                
                
            }
            
            
            
            
            
            
        }
        
        
        return true;
        
    }
};