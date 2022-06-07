class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        
        int m=s.size();
        int n=f.size();
        
        vector<vector<int>> ans;
        if(n==0 || m==0){
            return ans;
        }
        
        //O(M*N)
        //O(M+N)
        
        int i=0;
        int j=0;
        
        while(i<n && j<m){
            
            if(min(f[i][1],s[j][1])>=max(f[i][0],s[j][0])){
                
                int l=max(f[i][0],s[j][0]);
                int r=min(f[i][1],s[j][1]);
                
                ans.push_back({l,r});
                
            }
            
            
            if(f[i][1]<s[j][1]){
                i++;
            }
            
            else{
                j++;
            }
            
            
            
        }
        
        
        return ans;
        
    }
};