class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        vector<int> inorder(n,0);
        
        for(int i=0;i<n;i++){
            
            inorder[i]=graph[i].size();
            
            for(auto v:graph[i]){
                
                adj[v].push_back(i);
                
            }
        }
        queue<int> q;
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(inorder[i]==0)q.push(i);
        }
        
        while(!q.empty()){
            
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto c:adj[t]){
                inorder[c]--;
                if(inorder[c]==0){
                    q.push(c);
                }
            }
            
            
            
        }
        
        
    sort(ans.begin(),ans.end());
     return ans;   
        
        
    }
};