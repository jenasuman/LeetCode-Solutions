class Solution {
    int dp[502][502];
    int f(int i,int j,vector<int>& nums1,vector<int>& nums2){
        
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        
        if(nums1[i]==nums2[j]){
            return dp[i][j]=1+f(i-1,j-1,nums1,nums2);
        }
        
        int neglectFromNums1=f(i-1,j,nums1,nums2);
        int neglectFromNums2=f(i,j-1,nums1,nums2);
        
        return dp[i][j]=max(neglectFromNums1,neglectFromNums2);
        
        
        
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        
       // perfect match--- i-1 j-1
       // not a perfect match-- max((i-1,j),(i,j-1));
        int n=nums1.size();
        int m=nums2.size();
        int i=n-1;
        int j=m-1;
        memset(dp,-1,sizeof(dp));
        return f(i,j,nums1,nums2);
        
        
    }
};