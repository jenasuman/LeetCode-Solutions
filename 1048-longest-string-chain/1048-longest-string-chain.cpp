class Solution {

    
    bool f(string& s1,string& s2){
    
        int i=0;
        int j=0;
        
        int n=s1.size();
        bool flag=false;
        
        for(;i<n;i++){

            if(s1[i]==s2[j]){
                j++;
            }
            else{
                if(!flag)flag=true;
                else return false;
            }
         }
        
        return true;
        
    }
public:
    static bool comp(string& s1,string& s2){
        
        return s1.size()<s2.size();
        
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),comp);
        int n=words.size();
        
        vector<int> ans(n,1);
        int res=1;
        for(int i=1;i<n;i++){
            
            for(int j=i-1;j>=0;j--){
                
                int m=words[i].size();
                int l=words[j].size();
                if((l+1)==m){
                 if(f(words[i],words[j])){
                    ans[i]=max(ans[i],1+ans[j]);
                }
                }
                
            }
            
            res=max(res,ans[i]);
            
        }

        return res;
        
     
        
    }
};