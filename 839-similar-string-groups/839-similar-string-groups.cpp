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
        
        unordered_map<string,int> m;
        int count=0;
        int n=strs.size();
        for(int i=0;i<n;i++){
            
            if(m.find(strs[i])==m.end()){
                m[strs[i]]=count;
                count++;
            }
            
            
        }
        
        // n=m.size();
        rank.resize(count);
        parent.resize(count);
        
        // n=strs.size();
        
        for(int i=0;i<count;i++){
            parent[i]=i;
            rank[i]=i;
        }
        
        
        
        for(int k=1;k<n;k++){
            string temp=strs[k];
            int l=strs[k].size();
            for(int i=0;i<l;i++){
                
                for(int j=i+1;j<l;j++){
                    
                    swap(temp[i],temp[j]);
                    if(m.find(temp)!=m.end())
                        dsu(m[temp],m[strs[k]]);
                    
                    swap(temp[i],temp[j]);
                    
                }
                
                
            }

            
        }
        
        int ans=0;
        
        for(int i=0;i<count;i++){
            
            if(i==parent[i])ans++;
            
        }
        
        return ans;
    }
    
};