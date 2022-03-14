// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        int mi=INT_MAX;
        int ma=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(arr[i]>0)mi=min(arr[i],mi);
            ma=max(arr[i],ma);
        }
        
        if(ma==0)return 1;
        if(mi!=1)return 1;
        int dp[ma+1];
        
        memset(dp,-1,sizeof(dp));
        
        for(int i=0;i<n;i++){
            if(arr[i]>0)dp[arr[i]]=1;
        }
        
        for(int i=1;i<=ma;i++){
            if(dp[i]==-1)return i;
        }
        
        return ma+1;
        
        
    } 
};

// { Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
}   // } Driver Code Ends