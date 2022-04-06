class Solution {
public:
    int mod=1e9+7;
    int threeSumMulti(vector<int>& arr, int target) {
        
        int n=arr.size();

        unordered_map<int,int> m;
        
        int count=0;
        
        for(int i=0;i<n;i++){
            
            count=(count+m[target-arr[i]])%mod;
            
            for(int j=0;j<i;j++){
                m[arr[i]+arr[j]]++;
            }
            
        }
     return count;
    }
};