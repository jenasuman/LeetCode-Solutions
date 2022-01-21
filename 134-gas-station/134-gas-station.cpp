class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        
        int total_gas=accumulate(gas.begin(),gas.end(),0);
        int total_cost=accumulate(cost.begin(),cost.end(),0);
        
        if(total_cost>total_gas)return -1;
        
        
        for(int i=0;i<n;i++){
            
            if(gas[i]==0 && cost[i]==0)continue;
            
            int profit=gas[i]-cost[i];
            
            if(profit<0){
                
                continue;
                
            }
            int j=(i+1)%n;
            while(profit>=0 && i!=j){
                
                profit=(profit+gas[j]-cost[j]);
                j=(j+1)%n;
                // cout<<profit<<"\n";
            }
            
            if(profit>=0 && i==j){
                return i;
            }
            
            
            
            
            
        }
        
        return -1;
        
    }
};