class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x==parent[x])return x;
        
        return parent[x]=find(parent[x]);
    }
    
    void dsu(int x,int y){
        
        x=find(x);
        y=find(y);
        
        if(x!=y){
            
            if(rank[x]<rank[y]){
                swap(x,y);
            }
            
            parent[y]=x;
            rank[x]+=rank[y];
            
            
        }
        
        
        
        
    }
    
    
    int numSimilarGroups(vector<string>& strs) {
        
        

        int n=strs.size();
        rank.resize(n);
        parent.resize(n);
        
        // n=strs.size();
        
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=1;
        }
        
        unordered_map<string,int> m;
        m[strs[0]]=0;
        
        for(int k=1;k<n;k++){
            string temp=strs[k];
            int l=strs[k].size();
            if(m.find(temp)!=m.end()){
                parent[k]=303;
                continue;
            }
            for(int i=0;i<l;i++){
                
                for(int j=i;j<l;j++){
                    
                    swap(temp[i],temp[j]);
                    if(m.find(temp)!=m.end()){
                        dsu(m[temp],k);
                    }    
                    
                    swap(temp[i],temp[j]);
                    
                }
                
                
            }
            if(m.find(strs[k])==m.end())
            m[strs[k]]=k; 
            
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            
            if(i==parent[i])ans++;
            
        }
        
        return ans;
    }
    
};