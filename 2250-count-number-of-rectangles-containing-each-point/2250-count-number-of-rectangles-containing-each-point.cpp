class Solution {
public:
 vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector <int> hs[102];
        for (auto rec : rectangles) {
            hs[rec[1]].push_back(rec[0]);
        }
        for (int i = 0; i < 102; ++i) {
            sort(hs[i].begin(), hs[i].end());
        }
 
        vector <int> res;
        for (auto point : points) {
            int x = point[0];
            int y = point[1];
            int total = 0;
            for (int j = y; j <= 101; ++j) {
                int l = 0, r = hs[j].size() - 1;
                int can =hs[j].end()-lower_bound(hs[j].begin(),hs[j].end(),x);
             
                total += can;
            }
            res.push_back(total);
        }
        return res;
    }
};