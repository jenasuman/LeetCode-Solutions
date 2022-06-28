class Solution {
public:
    int minDeletions(string s) {
        
         vector<int> v(26,0);
        
         for(auto c:s){
             v[c-'a']++;
         }
         
         priority_queue<int> pq;
        
         for(int i=0;i<26;i++){
             
             if(v[i]>0){
               pq.push(v[i]);
             }
         }

         int ans=0;
        
         while(!pq.empty()){
             
             int currTop=pq.top();
             pq.pop();
             
             if(!pq.empty() && pq.top()==currTop){
                 currTop--;
                 ans++;
                 if(currTop!=0)
                 pq.push(currTop);
             }
             
             
             
             
         }
        return ans;
    }
};