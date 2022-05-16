class Solution {
public:
    int ans;
        void solve(int col,int n,vector<string>& mat,vector<int>& leftRow,vector<int>& upperDiagonal,
               vector<int>& lowerDiagonal){
        if(col==n){
            ans++;
            return;
        }
        
        for(int row=0;row<n;row++){
            
            if(!leftRow[row] && !upperDiagonal[n-1+col-row] && !lowerDiagonal[row+col]){
                
                mat[row][col]='Q';
                leftRow[row]=1;
                upperDiagonal[n-1+col-row]=1;
                lowerDiagonal[row+col]=1;
                
                solve(col+1,n,mat,leftRow,upperDiagonal,lowerDiagonal);
                
                mat[row][col]='.';
                leftRow[row]=0;
                upperDiagonal[n-1+col-row]=0;
                lowerDiagonal[row+col]=0;
                
                
                
                
                
                
            }
            
            
            
            
        }
        
        
    }
    int totalNQueens(int n) {
        
        ans=0;
        
        vector<string> mat;
        
        string temp="";
        
        for(int i=0;i<n;i++)temp.push_back('.');
        
        for(int i=0;i<n;i++)mat.push_back(temp);
        
        vector<int> leftRow(n,0),upperDiagonal(2*n-1,0),lowerDiagonal(2*n-1,0);
        
        solve(0,n,mat,leftRow,upperDiagonal,lowerDiagonal);
        
        return ans;
        
        
        
    }
};