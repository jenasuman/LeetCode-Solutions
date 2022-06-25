class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        sort(begin(costs),end(costs));
        
        int n=costs.size();
        
        int i=0;
        
        int count=0;
        
        while(i<n && coins>0){
            
            if(coins<costs[i])break;
            
            coins-=costs[i];
            
            count++;
            i++;
            
        }
        
        return count;
    }
};