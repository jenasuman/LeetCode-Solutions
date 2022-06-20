class Solution {
public:
    static bool comp(string& s1,string& s2){
        
        return s1.size()>s2.size();
        
    }
    int minimumLengthEncoding(vector<string>& words) {
        
        int n=words.size();

        sort(words.begin(),words.end(),comp);
        int ans=0;
        unordered_map<string,int> m;
        
        for(auto s:words){
            m[s]++;
        }
        
        for(int i=0;i<n;i++){
            if(m[words[i]]>0){
                ans=ans+words[i].size()+1;

                int j=words[i].size()-1;
                int l=words[i].size();
                for(;j>=0;j--){

                    string temp=words[i].substr(j,l-j);
                    
                    m[temp]=0;
                    
                }
                
                
           } 
        }

    
        
        return ans;
        
    }
};