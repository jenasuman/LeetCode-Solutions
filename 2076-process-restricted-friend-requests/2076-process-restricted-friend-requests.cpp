class Solution {
public:
    int find(vector<int>& parent,int i){
        return parent[i]<0?i:parent[i]=find(parent,parent[i]);
    }
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        vector<bool> ans;
        
        vector<int> parent(n,-1);
    
        
        for(auto& r:requests){
            
            int v=find(parent,r[0]);
            int u=find(parent,r[1]);
            
            bool flag=true;
            
            if(u!=v){
                
                for(auto& i:restrictions){
                    
                    int p1=find(parent,i[0]);
                    int p2=find(parent,i[1]);
                    
                    if((v==p1 && u==p2)||(u==p1 && v==p2)){
                        flag=false;
                        
                        break;
                        
                    }
                    
                    
                }
                if(flag){
                parent[u]=v;
                }
                
            }
            
            
            
            ans.push_back(flag);
            
            
        }
        
        return ans;
        
    }
};