class Solution {
    using ll =long long int;
public:
    int minMoves(vector<int>& nums) {
        // priority_queue<ll,vector<ll>,greater<ll>> pq;
        
        ll sum=accumulate(begin(nums),end(nums),0);
        
        int n=nums.size();
        
        if(n==1)return 0;
        
    
        int mi=INT_MAX;
        for(auto i:nums){
            mi=min(mi,i);
        }
//         int count=0;
//         while(1){
            
//             vector<int> v;
//             int i=1;
//             bool flag=true;
//             while(i!=n){
//                 if(!v.empty() && pq.top()!=v.back())flag=false;
//                 v.push_back(pq.top());
//                 pq.pop();
//                 i++;
//             }
            
//             if(flag && (v.back()==pq.top())){
//                 break;
//             }
            
//             sum+=(n-1);
            
//             for(auto i:v){
//                 pq.push(i+1);
//             }
            
//             count++;
            
//         }
        
//         return count;
        
        return sum-((ll)(n)*(ll)(mi));
        
        
        
    }
};