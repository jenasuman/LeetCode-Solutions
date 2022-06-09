class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        unordered_map<int,int> m;
        int n=numbers.size();
        
        for(int i=0;i<n;i++){
            
            int currTarget=target-numbers[i];
            
            if(m.find(currTarget)!=m.end()){
                
                return {m[currTarget],i+1};
                
                
            }
            
            m[numbers[i]]=i+1;
            
            
            
        }
        
        return {};
        
    }
};