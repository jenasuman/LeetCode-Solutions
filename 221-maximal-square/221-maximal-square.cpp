class Solution {
public:
 
    int maximalSquare(vector<vector<char>>& matrix) {
        
       int n=matrix.size();
       int m=matrix[0].size();
        
       vector<vector<int>> v(n,vector<int>(m));
       bool flag=false; 
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               if(matrix[i][j]=='1'){v[i][j]=1,flag=true;}
               else v[i][j]=0;
           }
       } 
        if(flag==false)return 0;
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(v[i][j]==1){
                    v[i][j]=min({v[i-1][j],v[i][j-1],v[i-1][j-1]})+1;
                    
                }
                ans=max(ans,v[i][j]);
            }
        }
        
        return ans*ans;
    }
};