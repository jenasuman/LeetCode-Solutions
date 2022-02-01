class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n=prices.size();
        
        int right_max=prices[n-1];
        
        int ans=0;
        
        for(int i=n-2;i>=0;i--){
            
            ans=max(ans,right_max-prices[i]);
            
            right_max=max(right_max,prices[i]);
            
            
        }
        
        return ans;
        
    }
};