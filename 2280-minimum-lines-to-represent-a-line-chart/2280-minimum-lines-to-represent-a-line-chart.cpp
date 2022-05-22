class Solution {
public:
    int minimumLines(vector<vector<int>>& s) {
        
        sort(s.begin(),s.end());
        
        vector<long double> slope;
        
        int n=s.size();
        
        if(n==1)return 0;
        
        for(int i=1;i<n;i++){
            
            long double y=s[i][1]-s[i-1][1];
            long double x=s[i][0]-s[i-1][0];
            
            long double m=(y*1.0)/x;
            
            slope.push_back(m);
            
        }
        
        n=slope.size();
        
        int ans=1;
        
        for(int i=1;i<n;i++){
            if(slope[i]!=slope[i-1]){
                ans++;
            }
        }
        
        return ans;
    }
};