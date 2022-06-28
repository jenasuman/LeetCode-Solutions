class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
    
        stack<int> s;
        int n=nums.size();
        for(int i=0;i<n;i++){
            
            while(!s.empty() && s.top()>nums[i] && (n-i)>=(k+1)){
                
                s.pop();
                k++;
                
            }
            
            if(k>0){
                s.push(nums[i]);
                k--;
            }     
            
            
        }
        
        vector<int> ans;
        
        while(!s.empty()){
            int c=s.top();
            s.pop();
            ans.push_back(c);
        }
        reverse(begin(ans),end(ans));
        return ans;
        
        
    }
};