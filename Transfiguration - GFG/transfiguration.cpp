// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    
    public:
    int transfigure (string A, string B)
    {
    	// Your code goes here
    	
    	vector<int> vis(256,0);
    	
    	for(auto c:A){
    	    vis[c]++;
    	}
    	for(auto c:B){
    	    if(vis[c]==0){
    	        return -1;
    	    }
    	    vis[c]--;
    	}
    	int n=A.size();
    	int i=n-1;
    	int j=n-1;
    	int ans=0;
    	while(i>=0 && j>=0){
    	    
    	    if(A[i]==B[j]){
    	        j--;
    	    }
    	    else{
    	        ans++;
    	    }
    	    i--;
    	    
    	}
    	
    	return ans;
    	
    }
};

// { Driver Code Starts.


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution obj;
        cout << obj.transfigure (A, B) << endl;
    }
}  // } Driver Code Ends