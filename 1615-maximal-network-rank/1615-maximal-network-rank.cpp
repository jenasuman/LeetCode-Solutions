class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        
        vector<vector<int>> adj(n,vector<int>(n,0));
        vector<int> count(n,0);
        for(auto r:roads){
            adj[r[0]][r[1]]=1;
            count[r[0]]++;
            count[r[1]]++;
            adj[r[1]][r[0]]=1;
        }
        
        int ans=INT_MIN;
        
//         for(auto c:count)cout<<c<<" ";
//         cout<<endl;
        for(int i=0;i<n;i++){
            int temp=count[i];
            for(int j=i+1;j<n;j++){
                
                temp+=count[j];
                // if(i==2 && j==5)
                // cout<<adj[i][j]<<"\n";
                if(adj[i][j]==1){
                    temp--;
                }
                ans=max(ans,temp);
                temp-=count[j];
                if(adj[i][j]==1){
                    temp++;
                } 
            }
        }
        
        
        return ans;
        
    }
};