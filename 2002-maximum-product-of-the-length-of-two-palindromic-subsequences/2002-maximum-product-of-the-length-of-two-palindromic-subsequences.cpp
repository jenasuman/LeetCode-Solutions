class Solution {
   
    int n;
    bool isPallindrome(string& s){
        
        int i=0;
        int j=s.size()-1;
        
        while(i<j){
            if(s[i]!=s[j])return false;
            i++;
            j--;
        }
     
        return true;
        
        
    }
    int ans;
    void f(int index,string& s,string& s1,string& s2){

        if(index==n){
            
            if(isPallindrome(s1) && isPallindrome(s2)){
                
                int m=s1.size();
                int l=s2.size();
                
                ans=max(ans,l*m);
                
            }
            
            return;
            
            
        }
        
        
        
        //Not pick in any string
        f(index+1,s,s1,s2);
        
        //Pick in string 1
        s1.push_back(s[index]);
        f(index+1,s,s1,s2);
        s1.pop_back();
        
        //Pick in string 2
        s2.push_back(s[index]);
        f(index+1,s,s1,s2);
        s2.pop_back();
        
        
    }
    
    
public:
    int maxProduct(string s) {

        n=s.size();
        string s1="";
        string s2="";
        ans=INT_MIN;
        
        f(0,s,s1,s2);
        return ans;
        
    }
};