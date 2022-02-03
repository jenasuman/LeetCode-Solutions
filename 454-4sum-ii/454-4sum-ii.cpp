class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n=nums1.size();
 
      
        unordered_map<int,int> s;
        for(auto i:nums4){
            for(auto j:nums3){
                s[i+j]++;
            }
        }
        int count=0;
        int sum;
        for(int i=0;i<n;i++){
         
            for(int j=0;j<n;j++){
             
                int t=0-(nums1[i]+nums2[j]);
                
                if(s.find(t)!=s.end()){
                    count+=s[t];
                }
                
            }
                
        }
        
        return count;
        
        
    }
};