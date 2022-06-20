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
                string temp="";
                int j=words[i].size()-1;
                for(;j>=0;j--){
                    temp.push_back(words[i][j]);
                    // cout<<temp<<" ";
                    string s=temp;
                    reverse(begin(s),end(s));
                    if(m.find(s)!=m.end()){
                        m[s]=0;
                    }
                    
                }
                
                
           } 
        }

    
        
        return ans;
        
    }
};