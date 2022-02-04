class Solution {
public:
    using p=pair<long long,int>;
    int nthSuperUglyNumber(int n, vector<int>& primes) {
          vector<long long> dp;
          dp.push_back(1);
         priority_queue<p,vector<p>,greater<p>> pq;
          int m=primes.size();
          vector<int> index(m,0);
        
        for(int i=0;i<m;i++){
            
            pq.emplace(primes[i],i);    
            
        }
        
        while(dp.size()<n){
            
            auto t=pq.top();
            pq.pop();
            
            int curr=t.first;
            int id=t.second;
            
            if(dp.back()!=curr){
                dp.push_back(curr);
            }
            
            index[id]++;
            
            pq.emplace(dp[index[id]]*primes[id],id);
            
            
            
        }
        
        return dp.back();
        
        
    }
};