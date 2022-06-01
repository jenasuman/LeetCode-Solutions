class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        
        double prev=1; 
        double sum=0;
        for(auto v:customers){
            
            if(prev>v[0]){
            sum=sum+(prev+v[1]-v[0]);
            prev+=v[1];
            }
            else{
                sum=sum+(v[1]);
                prev=v[0]+v[1];
            }
            // cout<<prev<<" ";
            
            
        }
        int n=customers.size();
        return sum/n;
    }
};