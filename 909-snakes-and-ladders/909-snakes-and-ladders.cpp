class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
         int n=board.size();
         int m=board[0].size();
         int size=n*n;
         vector<int> v(size+1);
         vector<int> vis(size+1,0);
         int k=1;
         for(int i=0;i<m;i++){
             
             v[k]=board[n-1][i];
             k++;
             
         }
          int flag=1;
         for(int i=n-2;i>=0;i--){
             
             if(flag){
             for(int j=m-1;j>=0;j--){
                 
                 v[k]=board[i][j];
       
                 k++;
             }
             flag=0;    
             }
             else{
             for(int j=0;j<m;j++){
                 
                 v[k]=board[i][j];
              
                 k++;
             }
             flag=1;      
             }
             
             
         }
        
         queue<pair<int,int>> q;
         // cout<<v[17]<<"\n";
         q.push({1,0});
         vis[1]=true; 
         while(!q.empty()){
             
             
             int curr=q.front().first;
             int steps=q.front().second;
             q.pop();
             // cout<<curr<<"\n";
             if(curr==n*n){
                 return steps;
             }
             
             for(int i=1;i<=6;i++){
                 
                 if(curr+i<=n*n && vis[curr+i]==0){
                     vis[curr+i]=1;
                     if(v[curr+i]!=-1){
                         
                         q.push({v[curr+i],steps+1});
                         if(v[curr+i]==-1)vis[v[curr+i]]=1;

                         
                     }
                     else{
                         q.push({curr+i,steps+1});
                     }
                     
                     
                 }
                 
                 
                 
             }
             
             
             
             
             
             
             
         }
        
        
        return -1;
        
        
    }
};