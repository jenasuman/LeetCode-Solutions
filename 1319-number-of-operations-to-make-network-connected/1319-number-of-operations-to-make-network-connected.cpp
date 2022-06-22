class Solution {
    int findParent(int a,vector<int>& parent){
        if(parent[a]==-1)return a;
        
        
        return parent[a]=findParent(parent[a],parent);
        
        
        
    }
    
    void dsu(int a,int b,vector<int>& parent,vector<int>& rank){
        
        a=findParent(a,parent);
        b=findParent(b,parent);
        
        if(a!=b){
            
            if(rank[a]<rank[b]){
                swap(a,b);
            }
            
            parent[b]=a;
            rank[a]+=rank[b];
            
        }
        
        
        
        
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        int N=connections.size();
        if(N<(n-1)){
            return -1;
        }
        
        
        vector<int> parent(n,-1);
        vector<int> rank(n,1);
        
        for(auto v:connections){
            
            dsu(v[0],v[1],parent,rank);
            
            
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            
            if(parent[i]==-1){
                count++;
            }
        }
        
        
        return count-1;
        
        
        
        
        
      
    }
};