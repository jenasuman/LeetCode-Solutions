// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        
        if(n<2)return 0;
        
        int max_reach=arr[0];
        int jump=1;
        int curr_pos=arr[0];
        
        for(int i=1;i<n;i++){
          
          if(i>max_reach)return -1;
          if(i==n-1)return jump;
          max_reach=max(max_reach,arr[i]+i);
            
          if(i==curr_pos){
              jump++;
              curr_pos=max_reach;
          }  
              
            
        }
        return jump;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}
  // } Driver Code Ends