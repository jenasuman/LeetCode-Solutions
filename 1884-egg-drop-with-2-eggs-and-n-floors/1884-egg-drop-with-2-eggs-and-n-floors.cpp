class Solution {
public:
    int dp[1001][3];
    int f(int floors,int eggs){
        
        if(dp[floors][eggs]!=-1)return dp[floors][eggs];
        
        if(eggs==1)return floors;
        
        if(floors<=1)return floors;
        
        int ans=1e6;
        
        for(int i=1;i<=floors;i++){
            //Break
            int case1=f(i-1,eggs-1);
            //Not break
            int case2=f(floors-i,eggs);
            
            ans=min(ans,max(case1,case2)+1);
            
         }
        
        return dp[floors][eggs]=ans;
        
    }
    
    int twoEggDrop(int n) {
        
        //two eggs 
        memset(dp,-1,sizeof(dp));
        return f(n,2);
         
        
    }
};