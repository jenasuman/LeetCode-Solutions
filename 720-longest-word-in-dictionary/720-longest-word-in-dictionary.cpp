class Solution {
public:
    string longestWord(vector<string>& words) {
        
        //26*30
        
        unordered_map<string,int> dict;
        queue<string> q;
        for(auto w:words){
            dict[w]++;
            if(w.size()==1){
                q.push(w);
            }
        }
        string ans="";
        unordered_map<string,bool> vis;
        while(!q.empty()){
            
            string curr=q.front();
            q.pop();
            vis[curr]=true;
            if(curr.size()>ans.size()){
                ans=curr;
            }
            else if(curr.size()==ans.size()){
                ans=(ans<curr)?ans:curr;
            }
            for(int i=0;i<26;i++){
                
                char currChar='a'+i;
                curr.push_back(currChar);
                
            if(dict.find(curr)!=dict.end() && vis.find(curr)==vis.end()){
                    q.push(curr);
                    vis[curr]=true;
                }
                
                curr.pop_back();
                
                
                
            }
            
            
            
            
            
            
        }
        
        return ans;
    }
};