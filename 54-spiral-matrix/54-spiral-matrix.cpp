class Solution {
public:
    bool isNotValid(int r,int c,int n,int m,char dir,vector<vector<bool>>& vis){
         if(dir=='r')c++;
         else if(dir=='d')r++;
         else if(dir=='l')c--;
         else if(dir=='u')r--;
        
         return r<0 || r>=n || c<0 || c>=m || vis[r][c] ? true:false;
        
        
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        char dir='r';
        int r=0;
        int c=0;
        vector<int> ans;
        for(int i=0;i<n*m;i++)
        {
           ans.push_back(matrix[r][c]);
            visited[r][c]=true;
            
           if(isNotValid(r,c,n,m,dir,visited)){
               if(dir=='r')dir='d';
               else if(dir=='d')dir='l';
               else if(dir=='l')dir='u';
               else if(dir=='u')dir='r';
           } 
            
           if(dir=='r')c++;
           else if(dir=='d')r++;
           else if(dir=='l')c--;
           else if(dir=='u')r--;
            
            
            
        }        
        return ans;
    }
};