class Solution {
public:
    void nextPermutation(string& num){
        
        int n=num.size();
        
        int k;
        
        for(k=n-2;k>=0;k--){
            if(num[k]-'0'<num[k+1]-'0'){
                break;
            }
        }
        if(k<0){
            reverse(num.begin(),num.end());
        }
        else{
            
            for(int i=n-1;i>=0;i--){
                if(num[i]-'0'>num[k]-'0'){
                    swap(num[i],num[k]);
                    break;
                }
            }
            
            reverse(num.begin()+k+1,num.end());
            
            
            
            
        }
        
        
        
    }
    int getMinSwaps(string num, int k) {
        //Next Permutation very important
        string s=num;
        int n=num.size();
        while(k--){
            nextPermutation(s);
        }
        // cout<<num;
        int i=0;
        // int j=0;
        int count=0;
        while(i<n){
            int j=i;
            while(s[i]!=num[j]){
                j++;
            }
            while(i<j){
                swap(num[j],num[j-1]);
                j--;
                count++;
            }
            
            i++;
            
            
        }
        
        
        return count;
    }
};