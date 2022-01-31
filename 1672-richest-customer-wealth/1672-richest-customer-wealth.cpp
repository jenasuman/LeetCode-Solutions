class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        
        int n=accounts.size();
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            int temp=0;
            
            for(auto j:accounts[i]){
                
                temp+=j;
                
                
            }
            
            
            ans=max(temp,ans);
            
        }
        
        
        return ans;
    }
};