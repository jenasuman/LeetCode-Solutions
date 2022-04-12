class Solution {
public:
    int maxCoins(vector<int>& piles) {
        
        sort(piles.begin(),piles.end());
        
        // for(auto i:piles)cout<<i<<" ";
        int n=piles.size();
        int j=n-1;
        int i=0;
        
        bool flag=false;
        int ans=0;
        while(i<j){
            
            if(flag)
            {
                ans+=piles[j];
                flag=false;
                j--;
                i++;
            }       
            else{
                j--;
                flag=true;
            }
            
            
        }
        
        
        return ans;
        
        
    }
};