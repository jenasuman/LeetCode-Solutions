class Solution {
public:
    int n;
    long long int dp[100004];
    long long int f(int i,vector<int>& nums,int k){
        
        
        if(i==(nums.size()-1)){
            return nums[i];
        }
        if(i>n-1){
            return INT_MIN; 
        }   
        
        if(dp[i]!=-1)return dp[i];
        
        long long int ans=INT_MIN;
        
        for(int j=1;j<=k;j++){
            

                long long int x=f(i+j,nums,k);
                if(x!=INT_MIN){
                long long int currAns=nums[i]+x;
                ans=max(currAns,ans);
                }
           
            
            
            
        }
        
      return dp[i]=ans;  
        
        
    }
    using pi=pair<int,int>;
    int maxResult(vector<int>& nums, int k) {
    
        n=nums.size();
        priority_queue<pi> pq;
        
        vector<int> dp(n);
        
        for(int i=n-1;i>=0;i--){
            
            
            while(!pq.empty() && pq.top().second>(i+k)){
                
                pq.pop();
                
                
            }
            
            dp[i]=nums[i];
            
            // cout<<dp[i]<<" "<<(pq.empty())<<"\n";
            
            dp[i]+=(!pq.empty())?pq.top().first:0;
            
            // if(!pq.empty())cout<<pq.top().first<<"\n";
            
            pq.push({dp[i],i});
            
            
            
        }

        return dp[0];
        
        
        
        
    }
};