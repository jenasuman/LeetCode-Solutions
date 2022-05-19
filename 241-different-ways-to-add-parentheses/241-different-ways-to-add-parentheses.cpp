class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        
        vector<int> results;
        
        int n=s.size();
        bool flag=true;
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='+' || s[i]=='-' || s[i]=='*'){
                
                flag=false;
                vector<int> left=diffWaysToCompute(s.substr(0,i));
                vector<int> right=diffWaysToCompute(s.substr(i+1));
                
                
                for(auto k:left){
                    
                    for(auto j:right){
                        
                         if(s[i]=='+'){
                             results.push_back(k+j);
                         }    
                         else if(s[i]=='-'){
                             results.push_back(k-j);
                         }
                        else results.push_back(k*j);
                        
                        
                    }
                }
                
                
                
                
                
                
                
                
            }
            
            
            
            
        }
        
        if(flag){
            results.push_back(stoi(s));
        }
        
        return results;
        
    }
};