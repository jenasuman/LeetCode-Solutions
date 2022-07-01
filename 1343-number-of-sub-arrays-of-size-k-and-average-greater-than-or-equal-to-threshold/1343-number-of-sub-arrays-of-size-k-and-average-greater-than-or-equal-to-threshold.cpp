class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int t) {
        
        int i=0;
        int j=0;
        int n=arr.size();
        int sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            
            sum+=arr[i];
            
            if((i-j+1)>k){
                
                sum-=arr[j];
                j++;
                
            }
            
            if((i-j+1)==k)ans+=(t*k<=sum);
            // cout<<j<<" "<<sum<<"\n";
            
            
            
        }
        
        return ans;
        
        
    }
};