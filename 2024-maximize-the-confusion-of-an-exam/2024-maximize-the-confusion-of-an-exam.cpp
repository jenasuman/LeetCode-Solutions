class Solution {
public:
    int maxConsecutiveAnswers(string a, int k) {
        int countF=0;
        int countT=0;
        
        int ans=1;
        int i=0;
        int j=0;
        int n=a.size();
        for(;i<n;i++){
            
            countF+=(a[i]=='F');
            countT+=(a[i]=='T');
            
            while(countF>k && countT>k){
                countF-=(a[j]=='F');
                countT-=(a[j]=='T');
                
                j++;
            }
            
            ans=max(ans,i-j+1);
            
            
        }
        
        return ans;
        
    }
};