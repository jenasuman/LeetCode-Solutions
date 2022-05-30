class Solution {
public:
    int dx[4]={1,-1,0,0};
    int dy[4]={0,0,-1,1};

    bool solve(vector<vector<char>>& board, string word,int index,int x,int y){
         int n=board.size();
        int m=board[0].size();
        if(index==word.size()-1 && board[x][y]==word[index])return true;
        
        if(board[x][y]!=word[index])return false;
        
        board[x][y]='#';
        
        for(int i=0;i<4;i++){
            
            int currX=x+dx[i];
            int currY=y+dy[i];
            
            // cout<<currX<<" "<<currY<<"\n";
            
         if(currX<n && currX>=0 && currY>=0 && currY<m && board[currX][currY]!='#'){
                 
               // cout<<"hello";
                if(solve(board,word,index+1,currX,currY))return true;
                
            }
            
            
            
        }
        board[x][y]=word[index];
        
        return false;
        
        
    }
    bool exist(vector<vector<char>>& board, string word) {
        
        int n=board.size();
        int m=board[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               
                if(solve(board,word,0,i,j))return true;
                
                
            }
        }
        
        return false;
        
    }
};