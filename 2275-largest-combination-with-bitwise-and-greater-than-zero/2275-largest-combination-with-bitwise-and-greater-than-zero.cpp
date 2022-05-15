class Solution {
public:
    int largestCombination(vector<int>& candidates) {
     
        vector<int> bitFrequency(32);
        
        for(auto i:candidates){
            
            int bit=31;
            
            while(i>0){
                
                bitFrequency[bit]+=i%2;
                i/=2;
                bit--;
            }
            
            
            
        }
        
        int ans=0;
        
        for(auto i:bitFrequency){
            ans=max(ans,i);
        }
        return ans;
    }
};