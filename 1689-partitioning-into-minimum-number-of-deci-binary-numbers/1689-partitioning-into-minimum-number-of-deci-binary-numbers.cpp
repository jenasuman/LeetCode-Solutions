class Solution {
public:
    int minPartitions(string n) {
  
           int ans=0;
           for(auto i:n){
               int currDigit=(i-'0');
               ans=max(ans,currDigit);
           }
        
           return ans;
 
          
    }
};