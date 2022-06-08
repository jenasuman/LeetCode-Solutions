class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
       
        int n=arr.size();
        
        int ans;
        int r=n-1;
        for(;r>=1;r--){
            
            if(arr[r]<arr[r-1])break;
            
        }
        
        ans=r;
        // cout<<r<<"\n";
        int l=0;
        
        while(l<n-1 && l<r){
            
            if(r<n && arr[l]>arr[r]){
                r++;
            }
            else{
                // cout<<r-l-1<<"\n";
                ans=min(ans,r-l-1);
                if(arr[l]>arr[l+1])break;
                l++;
            }
            
            
            
        }
        
     return ans;
    }
};