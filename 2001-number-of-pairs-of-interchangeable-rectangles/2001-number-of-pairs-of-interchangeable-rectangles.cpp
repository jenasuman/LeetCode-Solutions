class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
     
        int n=rectangles.size();
        long long int ans=0;
        vector<double> ratio(n);
        
        for(int i=0;i<n;i++){
            
            ratio[i]=(rectangles[i][0]/(rectangles[i][1]*1.0));
        }
        unordered_map<double,long long int> m;
        
        for(int i=0;i<n;i++){
            if(m.find(ratio[i])!=m.end()){
                ans+=m[ratio[i]];
            }    
            m[ratio[i]]++;
        }
        
        return ans;
        
        
    }
};