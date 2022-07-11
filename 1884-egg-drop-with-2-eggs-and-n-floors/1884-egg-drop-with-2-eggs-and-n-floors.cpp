class Solution {
public:
    int dp[1001][1001][3];
    int f(int ground,int top,int n){
      
        if(top-ground+1<=1){
            return top-ground+1;
        }
        
        if(n==1){
            return top-ground+1;
        }
        if(dp[ground][top][n]!=-1)return dp[ground][top][n];
        
      
        int count=INT_MAX;
        for(int i=ground;i<=top;i++){
            
            int case1=f(i+1,top,n);
            int case2=f(ground,i-1,n-1);
            
            int currCount=1+max(case1,case2);
            count=min(count,currCount);
        }
        
        return dp[ground][top][n]=count;
        
        
    }
    
    int twoEggDrop(int n) {
        
        //two eggs 
        memset(dp,-1,sizeof(dp));
        return f(1,n,2);
         
        
    }
};