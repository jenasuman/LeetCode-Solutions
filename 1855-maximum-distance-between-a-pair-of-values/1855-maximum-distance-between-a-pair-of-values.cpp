class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
     
        int n=nums1.size();
        int m=nums2.size();
        
        int i=0;
        int j=0;
        
        int ans=0;
        
        while(i<n && j<m){
            
            
            while(j<i && j<m)j++;
                
            if(j==m)break;
            
            if(nums1[i]<=nums2[j]){
                
                ans=max(ans,(j-i));        
                j++;

            }
            else{
                
                i++;
                
                
            }
            
            
            
            
            
            
        }
        
        
        return ans;
        
        
    }
};