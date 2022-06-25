class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        

        
        int countL=0;
        int n=nums.size();
        
        int currMax=nums[0];
        
        for(int i=0;i<n;i++){
            
            if(nums[i]<currMax){
                countL++;
            }
            else{
                currMax=nums[i];
            }
            
        }
        
        int countR=0;
        int currMin=nums[n-1];
        for(int i=n-1;i>=0;i--){
            
            
            if(currMin<nums[i]){
                countR++;
            }
            else{
                currMin=nums[i];
            }
            
            
            
            
            
        }
     
        return (countL<=1 || countR<=1);
        
        
    }
};