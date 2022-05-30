class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
     
      // Using LIS we can do it in O(nlog(n)) time;
        
        int firstMin=INT_MAX;
        int secondMin=INT_MAX;
        
        for(auto i:nums){
            
            if(i<=firstMin){
                firstMin=i;
            }
            else if(i<=secondMin){
                secondMin=i;
            }
            else{
                return true;
            }
            
            
            
            
            
        }
        
        return false;
        
    }
};