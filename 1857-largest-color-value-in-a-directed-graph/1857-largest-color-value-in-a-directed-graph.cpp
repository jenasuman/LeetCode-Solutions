class Solution {
public:
    int largestPathValue(string color, vector<vector<int>>& edges) {
        
        int n=color.size();
        vector<int> adj[n];
        vector<int> inorder(n,0);
        
        for(auto v:edges){
            
            adj[v[0]].push_back(v[1]);
            inorder[v[1]]++;
            
        }
        
        queue<int> q;
        

        vector<vector<int>> v(n,vector<int>(26,0));
        for(int i=0;i<n;i++){
            if(inorder[i]==0){
                q.push(i);
                v[i][color[i]-'a']++;
            }
        }
        int seen=0;
        int ans=0;
        while(!q.empty()){
            
            
              int curr=q.front();
    
              q.pop();
              
              
              int currAns=*max_element(begin(v[curr]),end(v[curr]));
              ans=max(currAns,ans);
              seen++;
             for(auto c:adj[curr]){
                 
                 for(int i=0;i<26;i++){
                     
                     v[c][i]=max(v[c][i],v[curr][i]+(i==(color[c]-'a')));
                     
                 }
                 
                 inorder[c]--;
                 
                 if(inorder[c]==0){
                     q.push(c);
                 }
                 
              }
            
        }

        
        if(seen!=n)return -1;
        
      
        return ans;
        
        
        
        
    }
};