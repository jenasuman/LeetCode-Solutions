class Solution {
    using ll=long long int;
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        
        queue<pair<int,int>> q;
        q.push({start,0});
        unordered_map<ll,int> m;
        // m[start]++;
        while(!q.empty()){
            
            
            int n=q.size();
            
            while(n--){
                
                auto p=q.front();
                q.pop();
                
                ll curr=p.first;
                int steps=p.second;
                
                if(curr==goal)return steps;
                
                if(curr>1000 || curr<0 || m.find(curr)!=m.end()){
                    continue;
                }
                m[curr]++;
                
                for(auto i:nums){
                    
                    ll x=curr+i;
                    ll y=curr-i;
                    ll z=curr^i;
                    
         
                        q.push({x,steps+1});
                    

                        q.push({y,steps+1});

                        q.push({z,steps+1});
                    
                    
                }
                
                
                
                
                
                
                
                
                
                
            }
            
            
            
            
            
            
            
            
            
            
            
        }
        
        
        
        
        return -1;
        
        
        
    }
};