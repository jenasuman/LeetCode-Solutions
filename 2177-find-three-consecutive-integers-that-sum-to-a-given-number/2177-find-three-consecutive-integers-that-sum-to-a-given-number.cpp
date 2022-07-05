class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        
          if(num%3==0){
              
              long long t=num/3;
              
              return {t-1,t,t+1};
              
          }      
        
        return {};
        

    }
};