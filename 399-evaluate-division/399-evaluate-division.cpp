class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        unordered_map<string,vector<pair<string,double>>> graph;
        
        int n=values.size();
        set<string> s;
        
        for(int i=0;i<n;i++){
            auto v=equations[i];
            s.insert(v[0]);
            s.insert(v[1]);
            graph[v[0]].push_back({v[1],1/values[i]});
            graph[v[1]].push_back({v[0],values[i]});
            
            
        }
        
        vector<double> ans;
        
        for(auto v:queries){
            
            string start=v[1];
            string end=v[0];
            
            if(s.find(start)==s.end()||s.find(end)==s.end()){
                ans.push_back(-1);
                continue;
            }
            
            queue<pair<string,double>> q;
            
            q.push({start,1});
            
            unordered_map<string,bool> vis;
            double res=-1;
            while(!q.empty()){
                
                string curr=q.front().first;
                double currVal=q.front().second;
                vis[curr]=true;
                q.pop();
                if(curr==end){
                    res=currVal;
                    break;
                }
                
                for(auto c:graph[curr]){
                    string cName=c.first;
                    double cVal=c.second;
                    if(vis.find(cName)==vis.end()){
                        q.push({cName,cVal*currVal});
                    }
                }
                
                
                
            }
            
            ans.push_back(res);
            
            
        }
        
        return ans;
        
    }
};