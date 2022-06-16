class Solution {
    vector<vector<int>> APS;
    int n;
    bool isPallindrome(string& s,vector<int>& temp){
        
        int i=0;
        int j=temp.size()-1;
        
        while(i<j){
            if(s[temp[i]]!=s[temp[j]])return false;
            i++;
            j--;
        }
        // cout<<s<<" ";
        return true;
        
        
    }
    void f(int index,string& s,vector<int>& temp){
          if(temp.size()!=0 && isPallindrome(s,temp)){
                   APS.push_back(temp);
           }
           if(index==n){
        
          
               return;
           }
           
           for(int i=index;i<n;i++){
               
               temp.push_back(i);
               f(i+1,s,temp);
               temp.pop_back();
               
               
           }
        
        
        return;
        
        
        
    }
    
    
public:
    int maxProduct(string s) {

        n=s.size();
        vector<int> curr;
        f(0,s,curr);
        int ans=INT_MIN;
        
        int m=APS.size();
        for(int i=0;i<m;i++){
            int h=APS[i].size();
            for(int j=i+1;j<m;j++){
                
                int l=APS[j].size();
                
                bool flag=true;
                
                for(int k=0;k<l;k++){
                    
         int index=lower_bound(APS[i].begin(),APS[i].end(),APS[j][k])-APS[i].begin();
                    
                    if(index!=APS[i].size() && APS[i][index]==APS[j][k]){
                        
                        flag=false;
                        break;
                        
                    }
                    
                }
                
                if(flag){
                    ans=max(h*l,ans);
                }
                
                
                
            }
            
            
            
        }
        

        
        return ans;
        
    }
};