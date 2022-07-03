// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    // Code here
	    
	    int inf=1e9;
	    vector<int> dis(n,inf);
	    int m=edges.size();
	    
	    
	    for(int i=0;i<=n-1;i++){
	        
	        for(int j=0;j<m;j++){
	            
	            int a=edges[j][0];
	            int b=edges[j][1];
	            
	            int wt=edges[j][2];
	            
	            if(dis[a]+wt<dis[b]){
	                dis[b]=dis[a]+wt;
	            }
	            
	            
	        }
	        
	        
	    }
	    
	    
	    bool flag=false;
	    
	    for(int j=0;j<m;j++){
	            
	            int a=edges[j][0];
	            int b=edges[j][1];
	            
	            int wt=edges[j][2];
	            
	            if(dis[a]+wt<dis[b]){
	                return 1;
	                dis[b]=dis[a]+wt;
	            }
	            
	            
	        } 
	    
	    
	    return 0;
	    
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>edges;
		for(int i = 0; i < m; i++){
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back({x,y,z});
		}
		Solution obj;
		int ans = obj.isNegativeWeightCycle(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends