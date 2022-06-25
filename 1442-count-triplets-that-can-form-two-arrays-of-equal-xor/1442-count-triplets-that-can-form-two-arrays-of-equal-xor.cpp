class Solution {
public:
    using ll=long long int;
    int countTriplets(vector<int>& arr) {
        
        int n=arr.size();
        int count=0;
        
        for(int i=0;i<n;i++){
            ll a=arr[i];
            for(int j=i+1;j<n;j++){
                
              
                ll b;
                for(int k=j;k<n;k++){
                    
                    if(k==j)b=arr[k];
                    
                    else b=b^arr[k];
                    
                    if(a==b){count++;
                     // cout<<i<<" "<<j<<" "<<k<<"\n";
                    }        
                    
                    
                }
                
                a=a^arr[j];
                
                
                
                
            }
            
            
            
            
            
            
            
        }
        
        
        return count;
        
        
    }
};