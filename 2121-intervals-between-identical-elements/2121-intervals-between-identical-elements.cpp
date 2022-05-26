class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        
         int n=arr.size();
        
        vector<long long> ans(n,0);
        
        unordered_map<int,pair<int,int>> m;
        
        vector<long long> prefix(n,0);
        
        for(int i=0;i<n;i++){
            
            
            if(m.find(arr[i])==m.end()){
                m[arr[i]]={i,1};
            }
            else{
                int prevIndex=m[arr[i]].first;
                int count=m[arr[i]].second;
                prefix[i]=prefix[prevIndex]+abs(i-prevIndex)*count;
                
                m[arr[i]]={i,count+1};
                
            }
            
            
            
        }
        unordered_map<int,pair<int,int>> m1;
        
       
        
        vector<long long> suffix(n,0);
       
        
        for(int i=n-1;i>=0;i--){
            
            
            if(m1.find(arr[i])==m1.end()){
               
                m1[arr[i]]={i,1};
            }
            else{
                int prevIndex=m1[arr[i]].first;
                int count=m1[arr[i]].second;
                suffix[i]=suffix[prevIndex]+abs(i-prevIndex)*count;
                
                m1[arr[i]]={i,count+1};
                
            }
            
            
            
        }
        
        for(int i=0;i<n;i++){
            // cout<<prefix[i]<<"-----"<<suffix[i]<<"\n";
            ans[i]=prefix[i]+suffix[i];
        }
        
        return ans;
    }
};