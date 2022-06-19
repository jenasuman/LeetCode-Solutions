class Solution {
    long long int dp[201][201];
    long long int f(int w,int h,vector<vector<int>>& price){
        
        // if(w==0 || h==0)return 0;
        if(dp[h][w]!=-1)return dp[h][w];
        
        
        
        long long int ans=price[h][w];
        
        for(int i=1;i<=w/2;i++){
            ans=max(ans,f(w-i,h,price)+f(i,h,price));
        }
        
        for(int i=1;i<=h/2;i++){
            ans=max(ans,f(w,h-i,price)+f(w,i,price));
        }
        
        return dp[h][w]=ans;
        
        
    }
public:
    long long sellingWood(int m, int n, vector<vector<int>>& prices) {
        vector<vector<int>> v(m+1,vector<int>(n+1,0));
        memset(dp,-1,sizeof(dp));
        // cout<<v[0][n];
        for(auto u:prices){
            v[u[0]][u[1]]=u[2];
        }
        
        return f(n,m,v);

    }
};