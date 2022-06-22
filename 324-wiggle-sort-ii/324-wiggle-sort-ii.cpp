class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        
        int n=nums.size();
        
        vector<int> great(nums);
        // vector<int> smaller(nums);
        
        sort(begin(great),end(great),greater<int>());
   
        
        int i=0;
    
        
        for(int k=0;k<n;k++){
            
            if(k%2!=0)
            nums[k]=great[i++];
      
            
        }
        
        for(int k=0;k<n;k++){
            
            if(k%2==0){
                
                nums[k]=great[i++];
                
            }
            
        }
        
        
    }
};