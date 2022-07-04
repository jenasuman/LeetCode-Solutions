class Solution {
public:
    using p=pair<int,int>;
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n=arr.size();
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++){
            
            m[arr[i]]++;
            
            
        }
        
        
        priority_queue<p,vector<p>,greater<p>> pq;
        
        
        for(auto i:m){
            
            pq.push({i.second,i.first});
            
            
        }
        
        
        while(k!=0 && !pq.empty())
        {
            
            auto curr=pq.top();
            
            int f=curr.first;
            int element=curr.second;
            pq.pop();
            f--;
            
            if(f!=0){
                
                pq.push({f,element});
                
            }
            
            
            k--;
        }        
        
        
        return pq.size();
        
    }
};