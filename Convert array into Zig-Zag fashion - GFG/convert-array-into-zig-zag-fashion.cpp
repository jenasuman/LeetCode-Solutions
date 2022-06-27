// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Program for zig-zag conversion of array
	void zigZag(int arr[], int n) {
      
        for(int i=0;i<n-1;i++){
    
        int temp=0;
        if(arr[i]>arr[i+1] && i%2==0 ){
            temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
        }
        if(arr[i]<arr[i+1] && i %2==1){
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
       
    }


	   
	    
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.zigZag(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends