class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        
        sort(begin(coins),end(coins));
        int count=1;
        int n=coins.size();
        
        for(auto coin:coins){
            
            if(count>=coin){
                count+=coin;
            }
            else{
                break;
            }
            
            
        }
        return count;
    }
};