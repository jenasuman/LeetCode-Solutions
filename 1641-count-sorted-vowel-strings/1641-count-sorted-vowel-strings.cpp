class Solution {
public:
    void solve(int index,int n,int& ans){
        if(n==0){
            ans++;
            return;
        }
        
        for(int i=index;i<5;i++){
            solve(i,n-1,ans);
        }
        
    }
    int countVowelStrings(int n) {
         vector<char> v;
         v.push_back('a');
         v.push_back('e');
         v.push_back('i');
         v.push_back('o');
         v.push_back('u');
         int ans=0;    
         for(int i=0;i<5;i++){
             
             solve(i,n-1,ans);
             
             
         } 
        return ans;
    }
};