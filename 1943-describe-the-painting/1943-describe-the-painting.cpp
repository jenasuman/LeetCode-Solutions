class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        
        vector<vector<long long>> ans;
        
        map<long long,long long> m;
        
       
        for(auto v:segments){
            m[v[0]]+=v[2];
            m[v[1]]-=v[2];
         }
          
        long long int prev=0;
        int start=-1;
        for(auto i:m){
            
           if(prev>0){
                ans.push_back({start,i.first,prev});
            }
            prev+=(i.second);
            start=i.first;
            
            
        }
        
        
        
        return ans;
        
    }
};