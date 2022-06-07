class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        
        int m=s.size();
        int n=f.size();
        
        vector<vector<int>> ans;
        if(n==0 || m==0){
            return ans;
        }
        
        for(int i=0;i<n;i++){
               
            int currStart=f[i][0];
            int currEnd=f[i][1];
            
            
            for(int j=0;j<m;j++){
                
                int givenStart=s[j][0];
                int givenEnd=s[j][1];
                
                if(max(currStart,givenStart)<=min(currEnd,givenEnd)){
                    
                    int r=max(currStart,givenStart);
                    int l=min(currEnd,givenEnd);
                    
                    ans.push_back({r,l});
                    
                    
                    
                }
               
                
                
                
                
                
                
            }
            
            
            
            
            
            
        }
        
        
        return ans;
        
    }
};