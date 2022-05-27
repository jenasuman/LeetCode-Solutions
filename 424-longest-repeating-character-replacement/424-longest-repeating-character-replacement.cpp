class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int start=0;
        int end=0;
        
        vector<int> count(26,0);
        int maxCount=0;
        
        int ans=1;
        int n=s.size();
        
        for(;start<n;start++){
            
            count[s[start]-'A']++;
            
            maxCount=max(count[s[start]-'A'],maxCount);
            
            while(start-end-maxCount+1>k){
                
                count[s[end]-'A']--;
                end++;
                
                for(int i=0;i<26;i++){
                    
                    maxCount=max(maxCount,count[i]);
                    
                }
             }
            
            ans=max(ans,start-end+1);
            
        }
        
        return ans;
    }
};