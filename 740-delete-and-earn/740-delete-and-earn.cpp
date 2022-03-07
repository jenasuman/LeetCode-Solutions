class Solution {
public:
    int dp[10001];
    int solve(int index,vector<int>& v){
        
        if(index>=v.size())return 0;
        if(dp[index]!=-1)return dp[index];
        return dp[index]=max((v[index]+solve(index+2,v)),solve(index+1,v));
        
    }
    int deleteAndEarn(vector<int>& nums) {
            vector<int> v(10001,0);
            memset(dp,-1,sizeof(dp));
            for(auto i:nums){
                v[i]+=i;
            }
        
            return solve(0,v);
             
    }
};