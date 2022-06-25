class Solution {
public:
bool f(long long finalSum,vector<long long>& ans,long long i){
        
           if(finalSum==0){
               return true;
           }
           if(finalSum-i<0)return false;
          
           ans.push_back(i);
           if(f(finalSum-i,ans,i+2))return true;
           ans.pop_back();
           
           return f(finalSum,ans,i+2);
        
    }
    vector<long long> maximumEvenSplit(long long finalSum) {
        
        if(finalSum%2!=0)return {};
        vector<long long> ans;
    
        f(finalSum,ans,2);
        
        return ans;
        //         if (s % 2) return {};
        // vector<long long> ans;
        // for (int i = 2; s - i >= i + 2; i += 2) {
        //     ans.push_back(i);
        //     s -= i;
        // }
        // ans.push_back(s);
        // return ans;

        
    }
};