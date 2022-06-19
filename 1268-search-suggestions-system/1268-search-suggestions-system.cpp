class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string s) {
        
        sort(products.begin(),products.end());
        
        unordered_map<string,int> m;
        
        int n=products.size();
        for(int i=0;i<n;i++){
            
            string temp="";
            
            for(auto c:products[i]){
                
                temp.push_back(c);
                
                if(m.find(temp)==m.end()){
                    m[temp]=i;
                }
                
                
            }
         }
        
        vector<vector<string>> ans;
        string temp="";
        int l=s.size();
        for(int k=0;k<l;k++){
            
            temp.push_back(s[k]);
            
            vector<string> res;
        
            // if(m.find(temp)==m.end())break;
            
            int i=m[temp];
            int j=i;
            for(;i<min(j+3,n);i++){
                if(products[i].substr(0,k+1)!=temp){
                    break;
                }
                res.push_back(products[i]);
            }
            
            ans.push_back(res);
            
            
        }
        
        return ans;
    }
};