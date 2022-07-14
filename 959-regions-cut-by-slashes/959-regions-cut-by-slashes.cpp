class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int count;
    int find(int x){
        
        if(x==parent[x])return x;
        
        return parent[x]=find(parent[x]);
        
    }
    void dsu(int x,int y){
        
        x=find(x);
        y=find(y);
        
        if(x==y){
            count++;
        }
        else{
            if(rank[x]<rank[y]){
                swap(x,y);
            }
            parent[y]=x;
            rank[x]+=rank[y];
        }
        
        
    }
    int regionsBySlashes(vector<string>& grid) {
    
        int n=grid.size();
        int dots=n+1;
        parent.resize(dots*dots);
        rank.resize(dots*dots);
        count=1;
        for(int i=0;i<parent.size();i++){
            parent[i]=i;
            rank[i]=1;
        }
        
        for(int i=0;i<dots;i++){
            for(int j=0;j<dots;j++){
                
                if(i==0 || j==0 || i==dots-1 || j==dots-1){
                    int cellNum=i*dots+j;
                    if(cellNum!=0)
                    dsu(0,cellNum);
                }
                
                
            }
        }
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                if(grid[i][j]=='/'){
                    int cellNo1=(i+1)*dots+j;
                    int cellNo2=i*dots+j+1;
                    
                  dsu(cellNo1,cellNo2);
                    
                }
                if(grid[i][j]=='\\'){
                    int cellNo1=(i+1)*dots+j+1;
                    int cellNo2=i*dots+j;
                    dsu(cellNo1,cellNo2);
                    
                }
                
                
            }
            
            
            
        }
        
        
        return count;

    }
};