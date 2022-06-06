class Square{
    
     
    
    public:
    int left;
     int right;
    int height;
    
    Square(int left, int right,int height){
        this->left=left;
        this->right=right;
        this->height=height;
    }
    
};

class Solution {
    
public:
    vector<int> fallingSquares(vector<vector<int>>& p) {
          
           vector<Square*> square;
           
           int n=p.size();
              
           vector<int> ans;
           int prevHeight=0;
        
           for(int i=0;i<n;i++){
               
               Square* curr=new Square(p[i][0],p[i][1]+p[i][0],p[i][1]);
               int maxHeight=curr->height;
               
               for(auto u:square){
                  // cout<<"hello"<<"\n"; 
                   if(max(u->left,curr->left)<min(u->right,curr->right)){
                       
                       maxHeight=max(maxHeight,curr->height+u->height);
                       
                   }
                   
                   
               }
               
               curr->height=maxHeight;
               
               square.push_back(curr);
               
               prevHeight=max(prevHeight,maxHeight);
               
               ans.push_back(prevHeight);
               
               
               
           }
        
        return ans;
        
           
    }
};