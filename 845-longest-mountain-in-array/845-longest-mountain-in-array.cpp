class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int n=arr.size();
        
        vector<int> prefix(n,1);
        vector<int> suffix(n,1);
        

        
        for(int i=1;i<n;i++){
            
            if(arr[i]>arr[i-1]){
                prefix[i]+=prefix[i-1];
            }
            
            
        }
        
        for(int i=n-2;i>=0;i--){
            
            if(arr[i]>arr[i+1]){
                suffix[i]+=suffix[i+1];
            }
            
            
        }
        
        int ans=1;
        
        for(int i=1;i<n-1;i++){
            
            if(suffix[i]!=1 && prefix[i]!=1)
            ans=max(ans,prefix[i]+suffix[i]-1);
            
            
        }
        
        return ans==1?0:ans;
        
    }
};