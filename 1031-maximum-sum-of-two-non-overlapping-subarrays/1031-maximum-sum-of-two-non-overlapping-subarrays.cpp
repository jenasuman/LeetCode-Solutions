class Solution {
public:
    int x,y;
    int solve(int index,vector<int>& nums,int f1,int f2,int dp[][2][2]){
        int n=nums.size();      
        if(index>=n)return 0;
    
        
        if(dp[index][f1][f2]!=-1)return dp[index][f1][f2];
        
        int choice1=solve(index+1,nums,f1,f2,dp);
        int choice2=0;
        int choice3=0;
        
        if(index+x<=n && !f1){
            
            int sum=0;
            
            for(int i=index;i<index+x;i++){
                sum+=nums[i];
            }
            
            sum+=solve(index+x,nums,1,f2,dp);
            choice2=sum;
            
        }
        if(index+y<=n && !f2){
            
            int sum=0;
            
            for(int i=index;i<index+y;i++){
                sum+=nums[i];
            }
            sum+=solve(index+y,nums,f1,1,dp);
            choice3=sum;
            
        }
        
        return dp[index][f1][f2]=max({choice1,choice2,choice3});
        
        
    }
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
       x=firstLen;
       y=secondLen; 
       int n=nums.size();
        int dp[n][2][2];
        
        for(int i=0;i<n;i++){
            
            for(int j=0;j<2;j++){
                
                for(int k=0;k<2;k++){
                    dp[i][j][k]=-1;
                }
                
            }
            
            
        }
        
        return solve(0,nums,false,false,dp);
        
        
    }
};