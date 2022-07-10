// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void f(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& ans,vector<int>& v){
       

        if(i==n-1 && j==m-1){
            // v.push_back(grid[i][j]);
            ans.push_back(v);
            return;
        }
        
        
        if(i+1<n){
            v.push_back(grid[i+1][j]);
            f(i+1,j,n,m,grid,ans,v);
            v.pop_back();
        }
        
        if(j+1<m){
            v.push_back(grid[i][j+1]);
            f(i,j+1,n,m,grid,ans,v);
            v.pop_back();
        }
        
        
        
        
        
        return;
        
        
    }
    vector<vector<int>> findAllPossiblePaths(int n, int m, vector<vector<int>> &grid)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(grid[0][0]);
        f(0,0,n,m,grid,ans,v);
        
        return ans;
        
        
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution ob;
        auto ans = ob.findAllPossiblePaths(n, m, grid);
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
  // } Driver Code Ends