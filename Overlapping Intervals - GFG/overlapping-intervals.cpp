// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<vector<int>> overlappedInterval(vector<vector<int>>& in) {
         // Code here
         sort(begin(in),end(in));
         vector<vector<int>> ans;
         int n=in.size();
         ans.push_back(in[0]);
         
         for(int i=1;i<n;i++){
             auto v=ans.back();
             if(in[i][0]<=v[1]){
                 
                 v[1]=max(in[i][1],v[1]);
                 
                 ans.pop_back();
                 
                 ans.push_back(v);
                 
             }
             else{
                 ans.push_back(in[i]);
             }
             
             
         }
         
         return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends