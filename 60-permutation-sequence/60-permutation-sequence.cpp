class Solution {
public:
    string getPermutation(int n, int k) {
         
        string ans="";
        
        int fact=1;
        vector<int> numbers;
    
        for(int i=1;i<n;i++){
            fact=fact*i;
            numbers.push_back(i);
        }
        k=k-1;
        numbers.push_back(n);
        while(1){
            
            ans=ans+to_string(numbers[k/fact]);
            
            numbers.erase(numbers.begin()+k/fact);
            
            if(numbers.size()==0){
                break;
            }
            
            k=k%fact;
            
            fact=fact/numbers.size();
            
         }
        return ans;
    }
};