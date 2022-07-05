class Solution {
public:
    unordered_map<int,vector<int>> adj;
    unordered_map<int,int> vis;
    void f(int src,int& count){
        
        count++;
        vis[src]=1;
        // cout<<src<<" ";
        
        for(auto c:adj[src]){
            
            if(vis.find(c)==vis.end()){
                f(c,count);
            }
            
        }
        
        
        
    }
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        
        unordered_map<int,int> m;
        
        for(int i=0;i<n;i++){
            m[nums[i]]=i;
        }

        for(int i=0;i<n;i++){
            
            if(m.find(nums[i]+1)!=m.end()){
            adj[nums[i]].push_back(nums[i]+1);
            adj[nums[i]+1].push_back(nums[i]);
            }
            
            
            
            
        }
        
        
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            
            if(vis.find(nums[i])==vis.end()){
                
                int count=0;
                
                f(nums[i],count);
                
                ans=max(ans,count);
                // cout<<endl;
            }
            
            
            
        }
        
        return ans==INT_MIN?0:ans;
        
        
    }
};