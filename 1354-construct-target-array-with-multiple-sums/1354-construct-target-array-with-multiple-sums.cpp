class Solution {
public:
    using ll= long long int;
    bool isPossible(vector<int>& target) {
        
        priority_queue<ll> pq;
        
        ll sum=0;
        
        for(auto x:target){
            pq.push(x);
            sum+=x;
        }
        
        while(pq.top()!=1){
            
            ll currTop=pq.top();
            pq.pop();
            
            sum-=currTop;
            
            if(sum==1){
                return true;
            }
    
            if(sum>currTop || sum==0 || (currTop%sum)==0){
                return false;
            }
            
           
            
            currTop=(currTop%sum);
            pq.push(currTop);
            
            sum+=(currTop);
            
            
            
            
            
            
            
            
            
            
        }
        
        
        return true;
        
        
        
    }
};