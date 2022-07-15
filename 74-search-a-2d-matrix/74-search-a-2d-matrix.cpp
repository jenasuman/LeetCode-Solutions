class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        //nlog(m)
        //log(m+n)
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> v(n);
       
        for(int i=0;i<n;i++){
            
            v[i]=matrix[i][0];
            
        }
        
        int index=lower_bound(begin(v),end(v),target)-begin(v);
        
        if(index!=n && v[index]==target)return true;
        
        if(index==0)return false;
        
        index--;
        
        int i=lower_bound(begin(matrix[index]),end(matrix[index]),target)-begin(matrix[index]);
        
        if(i==m)return false;
        
        if(matrix[index][i]==target)return true;
        
       return false;
        
        
    }
};