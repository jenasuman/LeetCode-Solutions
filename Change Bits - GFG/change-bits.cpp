// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
    void f(int N,vector<int>& bits){
        int i=0;
        while(N){
            
            // int m=N%2;
            
            // bits.push_back(1);
            bits[i]=1;
            i++;
            N=N/2;
            
            
            
        }
        
        
    }
  public:
    vector<int> changeBits(int N) {
        // code here
        
        vector<int> bits(32,0);
        
        f(N,bits);
        
        int ans=0;
        
        for(int i=0;i<32;i++){
            
            ans=ans+(bits[i]*pow(2,i));
            
            
        }
        // cout<<ans<<"\n";
        int diff=ans-N;
        return {diff,ans};
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        Solution ob;
        auto ans = ob.changeBits(N);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}  // } Driver Code Ends