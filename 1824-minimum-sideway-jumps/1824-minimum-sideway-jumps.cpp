class Solution {
public:
    int dp[500005][4];
    int f(int i,int lane,int n,vector<int>& obs){
        
        if(i==n-2)return 0;
         
        // if(obs[i]==lane)return 1e6;
        if(dp[i][lane]!=-1)return dp[i][lane];
        
        int case2=1e6,case3=1e6,case1=1e6;
        
        if(obs[i+1]!=lane){
            case1=f(i+1,lane,n,obs);
        }
        else{
        if(lane==2){
            if(obs[i]!=1)case2=f(i+1,1,n,obs);
            if(obs[i]!=3)case3=f(i+1,3,n,obs);
            case2=min(case3,case2);
        }
         if(lane==1){
            if(obs[i]!=2)case2=f(i+1,2,n,obs);
            if(obs[i]!=3)case3=f(i+1,3,n,obs);
            case2=min(case3,case2);
        }
         if(lane==3){
            if(obs[i]!=1)case2=f(i+1,1,n,obs);
            if(obs[i]!=2)case3=f(i+1,2,n,obs);
            case2=min(case3,case2); 
        }
        }
        return dp[i][lane]=min(case1,case2+1);
        
        
    }
    int minSideJumps(vector<int>& obs) {
        
        int n=obs.size();
        // int dp[n+1][4];
        memset(dp,-1,sizeof(dp));
        int i=0;
        return f(i,2,n,obs);
        
        
    }
};