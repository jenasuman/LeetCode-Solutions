class Solution {
public:
    //Finding LIS
    static bool comp(vector<int>& a,vector<int>& b){
        
        if(a[0]==b[0])return a[1]>b[1];
        
        return a[0]<b[0];
        
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        ios_base::sync_with_stdio(0);
        sort(envelopes.begin(),envelopes.end(),comp);
        
        int n=envelopes.size();
        
        if(n==1)return 1;
        
        vector<int> dp;
        
        
        for(int i=0;i<n;i++){
            int x=envelopes[i][1];
            int index=lower_bound(dp.begin(),dp.end(),x)-dp.begin();
            
            if(index>=dp.size()){
                dp.push_back(envelopes[i][1]);
            }
            else{
                dp[index]=envelopes[i][1];
            }
        
            
        }
        
        
        return dp.size();
    }
};