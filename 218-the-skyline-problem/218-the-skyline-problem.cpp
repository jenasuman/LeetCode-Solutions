class Solution {
    static bool comp(pair<int,int>& p1,pair<int,int>& p2){
        if(p1.first==p2.first)return p1.second>p2.second;
        return p1.first<p2.first;
    }
public:
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        
        vector<pair<int,int>> v;
        
        for(auto u:buildings){
            v.push_back({u[0],u[2]});
            v.push_back({u[1],(-1*u[2])});
        }
        
        sort(v.begin(),v.end(),comp);
  
        vector<vector<int>> ans;
        multiset<int> s;
        s.insert(0);
        int prev=0;
        
        for(auto [x,h]:v){
            
           if(h<0){
               
               auto it=s.find((-1*h));
               if(it!=s.end())s.erase(it);
               int curr=*(s.rbegin());
               if(prev>curr){
                   prev=curr;
                   ans.push_back({x,prev});
               }
               
           } 
           
           if(prev<h){
               prev=h;
               ans.push_back({x,h});
           }    
           
            s.insert(h);
            
            
            
            
        }
        
        return ans;
        
    }
};