class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area=(ax2-ax1)*(ay2-ay1)+(bx2-bx1)*(by2-by1);
        
        if(ax2<=bx1 || bx2<=ax1 || ay1>=by2 || by1>=ay2){return area;}
            
            vector<int> X;
            X.push_back(ax1);
            X.push_back(ax2);
            X.push_back(bx1);
            X.push_back(bx2);
            sort(X.begin(),X.end());
            
            vector<int> Y;
            Y.push_back(ay1);
            Y.push_back(ay2);
            Y.push_back(by1);
            Y.push_back(by2);
            sort(Y.begin(),Y.end());
            
            area=area-(X[2]-X[1])*(Y[2]-Y[1]);
        
        
        return area;
        
    }
};