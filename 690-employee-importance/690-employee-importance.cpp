/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
     unordered_map<int,vector<int>> adj;
     unordered_map<int,int> imp;
    unordered_map<int,int> vis;
    
    void dfs(int id,int& count){
        
        vis[id]=1;
        
        count+=imp[id];
        
        for(auto c:adj[id]){
            
            if(vis.find(c)==vis.end()){
                dfs(c,count);
            }
            
        }
        
        
        
    }
    int getImportance(vector<Employee*> employees, int id) {
        
        int n=employees.size();
       
        
        for(auto e:employees){
            
            int index=e->id;
            imp[index]=e->importance;
            for(auto i:e->subordinates)
            {
                adj[index].push_back(i);
             
            }            
            
        }
        
        
        
        int count=0;
        
        dfs(id,count);
        
        return count;
        
        
        
        
    }
};