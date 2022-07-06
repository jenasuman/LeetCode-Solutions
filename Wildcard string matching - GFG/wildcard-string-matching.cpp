// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    int n,m;
    bool f(int i,int j,string& w,string& p){
        
        if(j==m){
            
            for(;i<n;i++){
                if(w[i]!='*')return false;
            }
            return true;
        }
        
        if(i==n)return false;
        
        if(w[i]==p[j] || w[i]=='?'){
            return f(i+1,j+1,w,p);
        }
        
            
            if(w[i]=='*'){
                
                bool case1=f(i+1,j,w,p);
                bool case2=f(i,j+1,w,p);
          
                return case1|case2;
                
                    
            }
            
            
            
    
        return false;
        
    }
    bool match(string wild, string pattern)
    {
        // code here
         n=wild.size();
         m=pattern.size();
         
        return f(0,0,wild,pattern);
        
        
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends