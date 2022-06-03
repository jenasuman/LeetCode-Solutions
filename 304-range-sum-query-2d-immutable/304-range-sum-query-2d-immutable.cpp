class NumMatrix {
    vector<vector<int>> nums;
    int n;
    int m;
    
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
        
        nums.resize(n,vector<int>(m));
        
        
        nums[0][0]=matrix[0][0];
        
        for(int i=1;i<n;i++){
            nums[i][0]=nums[i-1][0]+matrix[i][0];
        }
        for(int i=1;i<m;i++){
            nums[0][i]=nums[0][i-1]+matrix[0][i];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                
                nums[i][j]=matrix[i][j]+nums[i-1][j]+nums[i][j-1]-nums[i-1][j-1];
                
                
                
            }
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<nums[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int rm=max(row1,row2);
        int cm=max(col1,col2);
        int rmi=min(row1,row2);
        int cmi=min(col1,col2);
        int temp=0;
        if(rmi!=0){
            temp=nums[rmi-1][cm];
        }
        if(cmi!=0){
            temp+=nums[rm][cmi-1];
        }
        if(rmi!=0 && cmi!=0){
            temp-=nums[rmi-1][cmi-1];
        }
        return nums[rm][cm]-temp;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */