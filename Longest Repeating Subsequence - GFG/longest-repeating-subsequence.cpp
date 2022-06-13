// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    int dp[1001][1001];
    int f(int i,int j,string str){
        
        if(i>=str.size() || j>=str.size())return 0;
        
        if(dp[i][j]!=-1)return dp[i][j];
        int case1=0;
        int case2=0;
        
        if(str[i]==str[j] && i!=j){
            case1=1+f(i+1,j+1,str);
        }
        else case2=max(f(i+1,j,str),f(i,j+1,str));
        
        return dp[i][j]=max(case1,case2);
        
    }
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    memset(dp,-1,sizeof(dp));
		    int n=str.size();
		    int i=0;
		    int j=i+1;
		    string s=str;
		    reverse(s.begin(),s.end());
		    return f(i,j,str);
		   
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends