class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // unordered_map<int,int> m;
        int n=numbers.size();
        
        //Can you do it in constant space????
        
        for(int i=0;i<n-1;i++){
            
            int currTarget=target-numbers[i];
            
            
            int index=lower_bound(begin(numbers)+i+1,end(numbers),currTarget)-begin(numbers);
            
            if(index!=n && numbers[index]==currTarget){
                
                return {i+1,index+1};
                
                
            }
            
            
            
        }
         
        
        
        return {};
        
    }
};