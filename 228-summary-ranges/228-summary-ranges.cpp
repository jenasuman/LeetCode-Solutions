class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        
        string temp="";
        
        int n=nums.size();
        if(n==0)return ans;
        int prev=0;
        int start=0;
        bool flag=false;
        for(int i=0;i<n-1;i++){
                if(!flag){
                    start=nums[i];  
                    flag=true;
                }
                if(nums[i]+1!=nums[i+1]){
                    
                     if(start==nums[i]){
                         temp+=to_string(nums[i]);
                     }
                     else{
                         temp+=to_string(start);
                         temp+="->";
                         temp+=to_string(nums[i]);
                     }
                    ans.push_back(temp);
                    flag=false;
                    temp="";
                      
                }
             
            
        }
        if(!flag){
            temp+=to_string(nums[n-1]);
            ans.push_back(temp);
        }
        else{
              temp+=to_string(start);
              temp+="->";
              temp+=to_string(nums[n-1]);
              ans.push_back(temp);
        }
        return ans;
    }
};