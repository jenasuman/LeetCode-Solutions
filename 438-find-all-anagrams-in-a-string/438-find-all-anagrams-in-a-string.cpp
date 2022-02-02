class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size();
        int k=p.size();
        
        int sum=0;
        
        vector<int> ans;
        
        if(k>n)return ans;
        unordered_map<char,int> m,a;
        for(auto c:p){
            m[c]++;
        }
        
        int j=0;
        int count=0;
        
        for(int i=0;i<n;i++){
            // cout<<j<<" "; 
            if(m.find(s[i])!=m.end()){
                
                a[s[i]]++;
                count++;
                
                while(a[s[i]]>m[s[i]]){
                    
                  
                        a[s[j]]--;
                        count--;
                        j++;
                   
                    
                }
                
                
                
                
            }
            else{
                j=i+1;
                a.clear();    
                count=0;
                continue;
                
                
            }
            
            
            if((i-j+1)==k)
            {    
                
                a[s[j]]--;
                if(count==k)
                ans.push_back(j);
                count--;
                j++;
                
            }
            
            
            
            
            
            
        }
        
        
        return ans;
        
    }
};