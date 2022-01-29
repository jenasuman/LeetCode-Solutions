class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
         int n=height.size();
         vector<int> left(n,0);
         vector<int> right(n,0);
         stack<int> s;
        
         for(int i=0;i<n;i++){
             
             while(!s.empty() && height[i]<=height[s.top()]){
                 s.pop();
             }
             
             if(s.empty())left[i]=0;
             else left[i]=s.top()+1;
             
             s.push(i);
             
             
             
         }
        
         while(!s.empty())s.pop();
        
         for(int i=n-1;i>=0;i--){
             
             while(!s.empty() && height[i]<=height[s.top()]){
                 s.pop();
             }
             
             if(s.empty()){
                 right[i]=n-1;
             }
             else right[i]=s.top()-1;
             
             s.push(i);
         }
        
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            
            ans=max(ans,height[i]*(right[i]-left[i]+1));
            
        }
        return ans;
    }
};