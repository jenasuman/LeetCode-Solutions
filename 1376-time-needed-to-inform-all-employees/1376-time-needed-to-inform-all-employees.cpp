class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> adj[n];
        int m=manager.size();
        for(int i=0;i<m;i++){
               
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
            
        }
        
        queue<pair<int,int>> q;
        
        q.push({headID,0});
        
        int currTime=0;
        int ans=INT_MIN;
        while(!q.empty()){
            
        auto p=q.front();
            
        int curr=p.first;
        int time=p.second;
        q.pop();   
        
        for(auto c:adj[curr]){
            
            q.push({c,informTime[curr]+time});
            
            
            
        }     
        
        if(informTime[curr]==0){
            ans=max(ans,time);
        }    
            
            
            
            
            
        }
        
        
        
        
        return ans;
        
        
        
    }
};