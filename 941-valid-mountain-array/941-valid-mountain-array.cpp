class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        
        int n=arr.size();
        int index=0;
        
        
        for(int i=1;i<n;i++){
            if(arr[index]<arr[i]){
                index=i;
            }
            
        }
        
        if(index==0 || index==n-1)return false;
        
        for(int i=index;i>=1;i--){
            
            if(arr[i]<=arr[i-1])return false;
            
        }
        
        for(int i=index+1;i<n;i++){
            if(arr[i]>=arr[i-1])return false;
        }
        
        return true;
        
        
    }
};