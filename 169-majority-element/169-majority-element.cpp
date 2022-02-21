class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        int n=nums.size();
        for(auto i:nums){
            m[i]++;
            
            if(m[i]>floor(n/2.0)){
                return i;
            }
        }
        return 0;
    }
};