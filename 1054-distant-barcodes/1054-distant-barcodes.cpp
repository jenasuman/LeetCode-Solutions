class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        if(barcodes.size() == 1)
        return {barcodes[0]};
        int n=barcodes.size();
        
        unordered_map<int,int> m;
        priority_queue<pair<int,int>> pq;
        
        for(auto i:barcodes){
            m[i]++;
        }
        for(auto i:m){
            pq.push({i.second,i.first});
        }
        
        vector<int> ans;
        
        pair<int,int> p1=pq.top();
        pq.pop();
        pair<int,int> p2=pq.top();
        pq.pop();
        
        while(p1.first && p2.first){
            
            ans.push_back(p1.second);
            p1.first--;
            ans.push_back(p2.second);
            p2.first--;
            
            if(p1.first){
                pq.push(p1);
            }
            if(p2.first){
                pq.push(p2);
            }
            
            if(!pq.empty()){
                p1=pq.top();
                pq.pop();
            }
            if(!pq.empty()){
                p2=pq.top();
                pq.pop();
            }
            
            
        }
        
        if(p1.first)
        {
            ans.push_back(p1.second);
        }
        return ans;
    }
};