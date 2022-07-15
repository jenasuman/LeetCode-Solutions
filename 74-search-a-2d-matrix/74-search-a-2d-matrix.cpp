class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
                  int n=matrix.size();
        int m=matrix[0].size();
        
        int l=0;
        int h=m*n-1;
        
        while(l<=h){
            
            int mid=(l+h)/2;
            
            int row=mid/m;
            int col=mid%m;
            
            if(matrix[row][col]==target)return true;
            
            if(matrix[row][col]>target){
                
                h=mid-1;
                
            }
            else{
                l=mid+1;
            }
            
            
            
        }
        return 0;      

    }
};