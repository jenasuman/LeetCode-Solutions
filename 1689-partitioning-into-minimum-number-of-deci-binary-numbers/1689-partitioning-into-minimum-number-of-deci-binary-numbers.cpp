class Solution {
public:
    int minPartitions(string n) {
           priority_queue<int,vector<int>,greater<int>> pq;
        
           for(auto i:n){
               int currDigit=(i-'0');
               pq.push(currDigit);
           }
        
           int ans=0;
        
           while(!pq.empty()){
               
               int curr=pq.top();
               pq.pop();
               
               ans=ans+(curr-ans);
            }
        return ans;
          
    }
};