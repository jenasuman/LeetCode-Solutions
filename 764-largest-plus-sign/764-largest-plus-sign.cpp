class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        
        
        vector<vector<int>> v(n,vector<int>(n,1));
        
        for(auto u:mines){
            v[u[0]][u[1]]=0;
        }
        
        vector<vector<int>> right(v);
        vector<vector<int>> left(v);
        vector<vector<int>> up(v);
        vector<vector<int>> down(v);
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                if((j>0) && v[i][j]==1)left[i][j]+=left[i][j-1];
                if((i>0) && v[i][j]==1)up[i][j]+=up[i-1][j];
                
            }
            
        }
        // cout<<left[3][1]<<"\n";
        for(int i=n-1;i>=0;i--){
            
            for(int j=n-1;j>=0;j--){
                
                if((j<n-1) && v[i][j]==1)right[i][j]+=right[i][j+1];
                if((i<n-1) && v[i][j]==1)down[i][j]+=down[i+1][j];
                
            }
            
        }
        int ans=0;
        
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<n;j++){
                
                int currAns=min({up[i][j],down[i][j],left[i][j],right[i][j]});
                // cout<<up[i][j]<<" "<<down[i][j]<<" "<<left[i][j]<<" "<<right[i][j]<<"\n";
                // cout<<i<<" "<<j<<" "<<currAns<<"\n";
                ans=max(ans,currAns);
                
                
            }
            
        }
        
        return ans;
        
        
    }
};