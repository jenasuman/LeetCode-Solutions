class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if(image[sr][sc]==color){
            return image;
        }
        int n=image.size();
        int m=image[0].size();
        
        queue<pair<int,int>> q;
        
        q.push({sr,sc});
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};

        int start=image[sr][sc];
                image[sr][sc]=color;
        while(!q.empty()){
            
            auto p=q.front();
            q.pop();
            int row=p.first;
            int col=p.second;
            
            for(int i=0;i<4;i++){
                
                int currR=row+dx[i];
                int currC=col+dy[i];
                
                if(currR>=0 && currC>=0 && currR<n && currC<m && image[currR][currC]==start)
                {
                    
                    image[currR][currC]=color;
                    q.push({currR,currC});
                    
                }
                
                
                
                
            }
            
            
            
            
            
            
            
        }
        return image;
        
    }
};