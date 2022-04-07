class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
          priority_queue <int> pq;
        
        for(auto c:stones){
            pq.push(c);
        }
        
        while(pq.size()>=2){
            int t1=pq.top();
            pq.pop();
            int t2=pq.top();
            pq.pop();
            
            int t=abs(t1-t2);
            if(t!=0)pq.push(t);
        }
        
        return pq.empty()?0:pq.top();
    }
};