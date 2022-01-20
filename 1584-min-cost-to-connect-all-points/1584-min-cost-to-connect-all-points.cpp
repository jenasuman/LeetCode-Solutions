class Solution {
public:
    int distance(vector<int>& v1,vector<int>& v2){
        
        return abs(abs(v1[0]-v2[0])+abs(v1[1]-v2[1]));
        
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
     
    int n = points.size();
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<pair<int,int>>> graph(n);
     
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            
            graph[i].push_back({j,distance(points[i],points[j])});
            graph[j].push_back({i,distance(points[i],points[j])});
        }
    }    
    
    vector<bool> visited(n,false);
       
    pq.push({0,0});
        
    int ans=0;
        
   while(!pq.empty()){
        
        
        
        int cNode=pq.top().second;
        int cDist=pq.top().first;
        pq.pop();
        
        if(visited[cNode]){
            continue;
        }
        
        visited[cNode]=true;
        ans+=cDist;
        
        for(auto v:graph[cNode]){
            
            int x=v.first;
            int weight=v.second;
            
            if(visited[x]==false){
                pq.push({weight,x});
            }
            
            
            
            
        }
        
        
        
        
    } 
        
        
        return ans;
        
        
        
    }
};