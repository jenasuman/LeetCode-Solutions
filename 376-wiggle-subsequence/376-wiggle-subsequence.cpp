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
        
        int n=nums.size();
        

        
        int up=1;
        int down=1;
        
        for(int i=1;i<n;i++){
            
            int diff=nums[i]-nums[i-1];
            
            if(diff>0){
                
                up=down+1;
                
                
            }
            else if(diff<0){
                
                down=up+1;
                
            }
        }
        
        return max(down,up);
        
        
    }
};