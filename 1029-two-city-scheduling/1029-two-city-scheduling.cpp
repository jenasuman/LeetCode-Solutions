class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        
        int cost=0;
        vector<int> diff;
        for(auto v:costs){
            
            cost+=v[0];
            
            diff.push_back(v[1]-v[0]);
            
            
        }
        sort(diff.begin(),diff.end());
        
        int n=costs.size();
        
        for(int i=0;i<n/2;i++){
            cost+=diff[i];
        }
        
        return cost;
        
    }
};