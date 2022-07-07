class Solution {
public:
    int dp[305][305];
    int f(vector<int>& nums,int i,int j){
        
        if(i>j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int ans=INT_MIN;
        for(int k=i;k<=j;k++){
            
            int temp=(nums[i-1]*nums[k]*nums[j+1])+f(nums,i,k-1)+f(nums,k+1,j);
            
            ans=max(temp,ans);
        }
        
        return dp[i][j]=ans;
        
        
    }
    int maxCoins(vector<int>& nums) {
        
        
        nums.push_back(1);
        nums.insert(begin(nums),1);
        int i=0;
        int j=nums.size()-1;
        memset(dp,-1,sizeof(dp));
        return f(nums,i+1,j-1);
        
        
    }
};