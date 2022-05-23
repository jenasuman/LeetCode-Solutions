class Solution {
public:
    int dp[605][101][101];
    pair<int,int> count(string& s){
        
        int countZeros=0;
        int countOnes=0;
        
        for(auto i:s){
            countZeros+=(i=='0');
            countOnes+=(i=='1');
        }
        
        return {countZeros,countOnes};
        
    }
    int solve(int index,vector<pair<int,int>>& v,int m,int n){
        
        int zeros=v[index].first;
        int ones=v[index].second;
        
        if(m==0 && n==0)return 0;
        
        if(index==0){
            
            if(m>=zeros && n>=ones){
                return 1;
            }
            
            else return 0;
            
        }
        if(dp[index][n][m]!=-1)return dp[index][n][m];
        int pick=0;
        
        if(m>=zeros && n>=ones)pick=1+solve(index-1,v,m-zeros,n-ones);
        
        int notPick=solve(index-1,v,m,n);
        
        return dp[index][n][m]=max(pick,notPick);
        
        
        
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<pair<int,int>> v;
        
        memset(dp,-1,sizeof(dp));
        
        for(auto s:strs){
            
            auto p=count(s);
            v.push_back(p);
            
        }
        
        int size=v.size();
        // vector<vector<vector<int>>> dp(size,vector<int>(n,vector<int>(m,-1)));
        
        return solve(size-1,v,m,n);
    }
};