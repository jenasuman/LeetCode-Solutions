class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int x=0;
        
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            x^=nums[i];
        }
        
        int bit=0;
        //Finding the first setBit
        for(int i=0;i<32;i++){
            
            if(x&(1<<i)){
                bit=i;
                break;
            }
        
            
        }
        
        int y=0;
        vector<int> ans;
        //XOR with all elements having setBit at the setBit
        for(int i=0;i<n;i++){
            if(nums[i]&(1<<bit)){
                y^=nums[i];
            }
            
        }
        
        ans.push_back(y);
        ans.push_back(x^y);
        
        return ans;
        
        
        
        
    }
};