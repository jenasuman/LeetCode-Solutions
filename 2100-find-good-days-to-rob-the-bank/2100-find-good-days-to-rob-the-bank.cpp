class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& nums, int time) {
        
        int n=nums.size();
        
        vector<int> prefix(n,0);
        
        vector<int> suffix(n,0);
    

        int j=0;
        int count=1;
        for(int i=1;i<n;i++){
            
              if(count==(time+1))
              {prefix[i-1]=1;count--;}
            
              if(nums[i]>nums[i-1]){
                   count=1;
              }
              else{
                  count++;
              }
            
             
            
            
        }
        if(count==time+1){
            prefix[n-1]=1;
        }
        
         count=1;        

        for(int i=n-2;i>=0;i--){
            
            if(count==(time+1)){
                suffix[i+1]=1;
                count--;
            }
            
            if(nums[i]>nums[i+1])count=1;
            
            else count++;
            
        

            
            
        }
        
        if(count==(time+1)){
            suffix[0]=1;
        }
    
        // for(int i=0;i<n;i++){
        //     cout<<prefix[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<n;i++){
        //     cout<<suffix[i]<<" ";
        // }
        // cout<<"\n";
        
        vector<int> ans;
        
        for(int i=time;i<n-time;i++){
            if(prefix[i]==suffix[i] && prefix[i]==1){
                ans.push_back(i);
            }
        }
        
        return ans;
        
    }
};