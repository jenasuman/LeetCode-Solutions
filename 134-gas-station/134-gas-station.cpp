class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n=gas.size();
        
//         int total_gas=0;
//         int total_cost=0;
        
//         for(int i=0;i<)
        
//         if(total_cost>total_gas)return -1;
        
        int curr_gas=0;
        int start=0;
        int prev_gas=0;
        
        for(int i=0;i<n;i++){
            
            curr_gas=curr_gas+(gas[i]-cost[i]);
            
            if(curr_gas<0){
                prev_gas+=curr_gas;
                curr_gas=0;
                start=i+1;
                curr_gas=0;
            }
            
            
        }
        
        return curr_gas+prev_gas>=0?start:-1;
        
    }
};