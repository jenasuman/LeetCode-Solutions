// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int ans=-1;
	    
	    int countZero=0;
	    int countOne=0;
	    
	    int n=S.size();
	    
	    for(int i=0;i<n;i++){
	        
	        countZero+=(S[i]=='0');
	        countOne+=(S[i]=='1');
	        
	        if(countZero>=countOne){
	            ans=max(ans,countZero-countOne);
	        }
	        else{
	            countZero=0;
	            countOne=0;
	        }
	          
	        
	    }
	    
	    return ans;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends