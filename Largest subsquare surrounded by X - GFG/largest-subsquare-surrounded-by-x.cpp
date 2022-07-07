// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    
    int largestSubsquare(int N, vector<vector<char>> arr) {
        // code here
    pair<int,int> dp[N][N];        
    int x = 0, y = 0;
    bool flag=0;

    for (int i = 0; i < N; i++)
    {
        x = 0;
        for (int j = 0; j < N; j++)
        {
            if (arr[i][j] == 'X'){
                flag=1;
                x += 1;
            }    
            else
                x = 0;
            dp[i][j].first = x;
        }
    }
 

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (arr[j][i] == 'X'){
                y += 1;
                flag=1;
            }        
            else
                y = 0;
            dp[j][i].second = y;
        }
    }
 
        
        
        int small;
        int ans=flag;
        
        for(int i=N-1;i>=1;i--){
            
            for(int j=N-1;j>=1;j--){
                
                small=min(dp[i][j].first,dp[i][j].second);
                
                while(small>ans){
                    
                if (dp[i][j - small + 1].second >= small
                && dp[i - small + 1][j].first >= small)ans=max(ans,small);
                
                    small--;
                    
                    
                    
                }
                
                
                
                
            }
            
            
            
            
            
            
        }
        
       return ans;
         
            
     }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<char>> v(N, vector<char>(N));
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cin >> v[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(N, v) << "\n";
    }
}  // } Driver Code Ends