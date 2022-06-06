class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        vector<vector<int>> res;
         
        intervals.push_back(newInterval);
        
        sort(intervals.begin(),intervals.end());
        
        res.push_back(intervals[0]);
        
        int n=intervals.size();
        
        for(int i=1;i<n;i++){
            
            int currL=intervals[i][0];
            int currR=intervals[i][1];
            
            auto v=res.back();
            
            if(v[1]>=currL){
                
                v[1]=max(currR,v[1]);
                
                res.pop_back();
                
                res.push_back(v);
            }
            else{
                
                res.push_back(intervals[i]);
            }
            
            
            
            
        }
        return res;
        
    }
};