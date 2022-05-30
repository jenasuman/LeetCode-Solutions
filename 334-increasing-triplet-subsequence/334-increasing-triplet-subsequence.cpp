class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
     
        
        int first=INT_MAX;
        int second=INT_MAX;
        
        for(auto i:nums){
            
            if(first>=i){
                first=i;
            }
            else if(i>first && i<second)second=i;
            
            else if(i>second){
                
                
                return true;
                
                
                
            }
            
            
            
            
            
        }
        return false;
        
        
    }
};