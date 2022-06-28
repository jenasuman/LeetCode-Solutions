class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry=0;
        
        int n=digits.size();
        vector<int> ans;
        if(digits[n-1]==9){
            ans.push_back(0);
            carry=1;
        }
        else{
            ans.push_back(digits[n-1]+1);
        }
        int i=n-2;
        while(carry!=0 && i>=0){
            
            if(digits[i]==9){
                ans.push_back(0);
            }
            else{
                ans.push_back(digits[i]+1);
                carry=0;
            }
            
            i--;
            
        }
        
        for(;i>=0;i--){
            ans.push_back(digits[i]);
        }
        
        if(carry!=0)ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};