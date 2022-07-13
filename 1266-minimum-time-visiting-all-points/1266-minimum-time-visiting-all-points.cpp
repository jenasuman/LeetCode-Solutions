class Solution {
public:

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        
        
        int n=points.size();
        int ans=0;

        for(int i=1;i<n;i++){
            
            int sx=points[i-1][0];
            int sy=points[i-1][1];
            int ex=points[i][0];
            int ey=points[i][1];
            int dx,dy;
            if(ex>=sx){
                dx=1;
            }
            else{
                dx=-1;
            }
            if(ey>=sy){
                dy=1;
            }
            else{
                dy=-1;
            }
             
            while(ex!=sx && sy!=ey){
                
                sx+=dx;
                sy+=dy;
                ans++;
            }
            
            ans+=(abs(sx-ex));
            ans+=(abs(sy-ey));
            
            
            
        }
        
        return ans;
        
        
    }
};