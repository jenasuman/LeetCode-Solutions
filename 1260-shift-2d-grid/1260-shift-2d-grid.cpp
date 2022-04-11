class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        
        int n=grid.size();
        int m=grid[0].size();
        
        // auto prev=grid[0];
        while(k--){
        vector<vector<int>> ans(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            ans[(i+1)%n][0]=grid[i][m-1];
        }
        
        for(int j=0;j<m-1;j++){
            // auto curr=grid[]
            for(int i=0;i<n;i++){
                
                ans[i][j+1]=grid[i][j];
                
            }
        }
        grid=ans;
        }
        
        return grid;
    }
};