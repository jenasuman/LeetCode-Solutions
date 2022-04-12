class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        
        int n=board.size();
        int m=board[0].size();
        
        int dx[8]={0,0,1,-1,1,-1,-1,1};
        int dy[8]={1,-1,0,0,1,-1,1,-1};
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<m;j++){
                
                int countOnes=0;
                int countZeros=0;
                
                for(int k=0;k<8;k++){
                    
                    int currX=i+dx[k];
                    int currY=j+dy[k];
                    
                    if(currX<n && currX>=0 && currY>=0 && currY<m){
                        
                        if(board[currX][currY]==1 || board[currX][currY]==-1){
                            countOnes++;
                        }
                        else{
                            countZeros++;
                        }
                        
                        
                    }
                    
                    
                    
                }
                
                if(board[i][j]==1 && (countOnes<2 || countOnes>3)){
                    board[i][j]=-1;
                }
                else if(board[i][j]==0 && (countOnes==3)){
                    board[i][j]=-2;
                }
                
                
            }
            
            
            
            
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==-1)board[i][j]=0;
                if(board[i][j]==-2)board[i][j]=1;
            }
        }
        
        
    }
};