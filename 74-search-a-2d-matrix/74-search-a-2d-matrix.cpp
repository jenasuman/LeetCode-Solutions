class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //nlog(m)
        //log(m+n)
        int n=matrix.size();
        int m=matrix[0].size();
        
        for(int i=0;i<n;i++){
            
            int index=lower_bound(begin(matrix[i]),end(matrix[i]),target)-begin(matrix[i]);
            
            if(index!=m && matrix[i][index]==target)return true;
        }
        
        return false;
        
        
    }
};