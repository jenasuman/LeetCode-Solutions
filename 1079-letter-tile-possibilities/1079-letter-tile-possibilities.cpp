class Solution {
    set<string> s;
    void f(int index,string& tiles,string& temp,vector<int>& vis){
        
        if(temp.size()!=0){
            // cout<<temp<<" ";
            s.insert(temp);
        }
        if(index==tiles.size()){
            return;
        }
        
        for(int i=0;i<tiles.size();i++){
            if(vis[i]==0){
            temp.push_back(tiles[i]);
            vis[i]=1;
            f(0,tiles,temp,vis);
            vis[i]=0;
            temp.pop_back();
            }    
            
        }
        
        
        
    }
public:
    int numTilePossibilities(string tiles) {
         int n=tiles.size();
         vector<int> vis(n,0);
         s.clear();
         int i=0;
         string temp="";
         f(i,tiles,temp,vis);
        
         return s.size();
         
    }
};