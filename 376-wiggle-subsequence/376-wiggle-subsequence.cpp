class Solution {
    int dp[1001][1001][2];
public:
    int f(int i,int j,int prev,vector<int>& nums){
        
        if(j>=nums.size())return 0;
        if(dp[i][j][prev]!=-1)return dp[i][j][prev];
        int case1=0;
        int case2=0;
        if(prev==0){
            int currDiff=nums[j]-nums[i];
            
            if(currDiff<0){
                case1=1+f(j,j+1,1,nums);
            }
            
            
        }
        if(prev==1){
            int currDiff=nums[j]-nums[i];
            
            if(currDiff>0){
                case1=1+f(j,j+1,0,nums);
            }
            
            
        } 
         
        case2=f(i,j+1,prev,nums);
        // cout<<case1<<" "<<case2<<"\n";
        return dp[i][j][prev]=max(case1,case2);
        
        
    }
    int wiggleMaxLength(vector<int>& nums) {
        
        memset(dp,-1,sizeof(dp));
        
        
        return max(f(0,1,1,nums),f(0,1,0,nums))+1;
        
        
        
    }
};