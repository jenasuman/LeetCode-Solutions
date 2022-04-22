class Solution {
public:
    long long int kadane(vector<int>& arr){
        long long int sum=0;
        long long int res=0;
        
        for(auto i:arr){
            if(i>sum+i){
                sum=i;
            }
            else sum+=i;
            if(res<sum)res=sum;
        }
        return res;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int n=arr.size();
        if(k==1)return kadane(arr);
        
        vector<int> arr2(2*n);
        
        for(int i=0;i<n;i++){
            arr2[i]=arr[i];
            arr2[i+n]=arr[i];
        }
        long long int mod=1e9+7;
        if(k==2)return kadane(arr2)%mod;
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum=(sum+arr[i])%mod;
            sum%=mod;
        }
        if(sum>0)return ((kadane(arr2)%mod)+((sum%mod)*(k-2))%mod)%mod;
        return kadane(arr2)%mod;
    }
};