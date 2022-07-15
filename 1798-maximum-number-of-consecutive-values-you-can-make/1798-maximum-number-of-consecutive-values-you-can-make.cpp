class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        
        sort(begin(coins),end(coins));
        int sum=1;
        int n=coins.size();
        
        for(auto coin:coins){
            
            if(sum>=coin){
                sum+=coin;
            }
            else{
                break;
            }
            
            
        }
        return sum;
    }
};