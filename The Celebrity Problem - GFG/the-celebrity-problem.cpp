// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
      vector<int> outorder(n);
      vector<int> inorder(n);
      for(int i=0;i<n;i++){
          for(int j=0;j<n;j++){
              if(M[i][j]==1){
                  outorder[j]++;
                  inorder[i]++;
              }
          }
      }
      bool flag=false;
      int ans=-1;
      for(int i=0;i<n;i++){
          if(outorder[i]==n-1 && inorder[i]==0)
          {
              if(flag==true){
                  return -1;
              }
              ans=i;
              flag=true;
           }
      }  
      
      return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}
  // } Driver Code Ends