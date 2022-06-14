class Solution {
    using ll=long long int;
public:
    int numOfSubarrays(vector<int>& arr) {
        
        int mod=1e9+7;
        
        int n=arr.size();
        
        vector<int> prefix(n,0);
        prefix[0]=arr[0];
        
         ll count=0;
        
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+arr[i];
        }
    
        vector<pair<ll,ll>> v;
        
        ll countOddSum=0;
        ll countEvenSum=0;
        
        for(auto i:prefix){
            v.push_back({countOddSum,countEvenSum});
            countOddSum+=(i%2!=0);
            countEvenSum+=(i%2==0);
        }
        
        
        for(int i=0;i<n;i++){
              if(prefix[i]%2!=0){
                  count=(count+1)%mod;
                  count=(count+v[i].second)%mod;
              }
              else{
                  count=(count+v[i].first)%mod;
              }
//               int current=prefix[i];
//               for(int j=0;j<i;j++){
                  
//                   current=current-arr[j];
                  
//                   if(current%2!=0){
//                      count=(count+1)%mod;
//                   }
                  
                  
//               }
            
              
            
        }
        
        return count%mod;
    }
};