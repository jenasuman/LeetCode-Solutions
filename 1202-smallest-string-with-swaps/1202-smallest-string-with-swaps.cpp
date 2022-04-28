class Solution {
public:
void getConnComb(vector<vector<int>>& graph,vector<bool>& visit, int u,vector<int>& comb){
            
          visit[u]=true;
          
          comb.push_back(u);
    
          for(auto i:graph[u]){
              if(!visit[i]){
                  getConnComb(graph, visit,i,comb);
              }
          }
     
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int V = s.size();
        vector<vector<int>> graph(V);
        for(auto p: pairs) {
            graph[p[0]].push_back(p[1]);
            graph[p[1]].push_back(p[0]);
        }
        vector<bool> visit(V, false);
        vector<vector<int>> ConnCombs;
		/*finding connected componets*/
        for(int u = 0; u < V; ++u) {
            if(visit[u] == false) {
                vector<int> comb;
               getConnComb(graph,visit,u,comb);
                ConnCombs.push_back(comb);
            }
        } 
        string ans=s;
        for(auto v:ConnCombs){
            
            vector<char> ConnChars;
            
            for(auto c:v){
                ConnChars.push_back(s[c]);
            }
            
            sort(ConnChars.begin(),ConnChars.end());
            sort(v.begin(),v.end());
            int j=0;
            for(auto i:v){
                ans[i]=ConnChars[j++];
            }
            
            
        }
        return ans;
    }
};