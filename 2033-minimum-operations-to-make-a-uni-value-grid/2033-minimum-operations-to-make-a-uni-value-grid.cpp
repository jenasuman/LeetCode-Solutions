class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        vector<int> v;
        int n=grid.size();
        int m=grid[0].size();
        int prev=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0 && j==0){
                    
                    prev=(grid[i][j]%x);
                    
                }
                else if(prev!=(grid[i][j]%x)){
                    return -1;
                }
                        
               v.push_back(grid[i][j]);         
                        
           }
        }
        
        sort(begin(v),end(v));
        n=v.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        
        prefix[0]=v[0];
        suffix[n-1]=v[n-1];
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+v[i];
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=suffix[i+1]+v[i];
        }
        
        int ans=INT_MAX;
        
        
        for(int i=0;i<n;i++){
            
            int left=((i+1)*v[i]-prefix[i]);
            int right=(suffix[i]-((n-i)*v[i]));
            
            int res=left+right;
            res/=x;
            ans=min(ans,res);
            
            
            
            
        }
        
        
         
        return ans;                
        
    }
};