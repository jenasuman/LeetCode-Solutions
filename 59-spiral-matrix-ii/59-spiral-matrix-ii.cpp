class Solution {
public:
      bool isNotValid(int r,int c,int n,int m,char dir,vector<vector<int>>& vis){
         if(dir=='r')c++;
         else if(dir=='d')r++;
         else if(dir=='l')c--;
         else if(dir=='u')r--;
        
         return r<0 || r>=n || c<0 || c>=m || vis[r][c]!=0 ? true:false;
        
        
     }
    vector<vector<int>> generateMatrix(int n) {
       
        int count=1;
        int i=0;
        int j=0;
        
        vector<vector<int>> ans(n,vector<int>(n,0));
        int r=0;
        int c=0;
        char dir='r';
        for(int i=1;i<=n*n;i++){
            
            ans[r][c]=i;
            
            if(isNotValid(r,c,n,n,dir,ans)){
                if(dir=='l')dir='u';
                else if(dir=='r')dir='d';
                else if(dir=='d')dir='l';
                else if(dir=='u')dir='r';
            }
            
            if(dir=='l')c--;
            if(dir=='d')r++;
            if(dir=='u')r--;
            if(dir=='r')c++;
            
            
        }
        
        
        return ans;
    }
};