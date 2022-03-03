class Solution {
public:
    typedef long long int ll;
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int ans=0;
        
        int n=nums.size();
        
        vector<map<ll,int>> dp(n);
        
        ll diff;
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<i;j++){
                
                diff=(ll)nums[i]-(ll)nums[j];
                
                if(dp[j].find(diff)!=dp[j].end()){
                    
                    dp[i][diff]+=dp[j][diff]+1;
                    
                    ans+=dp[j][diff];
                    
                }
                else{
                    dp[i][diff]++;
                }
                
                
            }
            
            
            
        }
        
        return ans;
        
        
    }
};