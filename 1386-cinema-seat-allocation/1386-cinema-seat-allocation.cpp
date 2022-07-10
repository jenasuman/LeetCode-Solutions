class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& r) {
        
        int ans=2*n;
        
        map<int,vector<int>> m;
        int l=r.size();
    
        for(int i=0;i<l;i++){
             m[r[i][0]].push_back(r[i][1]);
        }
        
        for(auto i:m){
            
            auto v=i.second;
            
            vector<int> b(11,0);
            
             for(auto j:v){
                 b[j]++;
             }
            
            if(b[4] && b[7]){
                ans-=2;
            }
            else if(b[4] && b[7]==0){
                if(b[8]==0 && b[9]==0 && b[6]==0)
                ans-=1;
                else ans-=2;
            }
            else if(b[7] && b[4]==0){
                if(b[2]==0 && b[3]==0 && b[5]==0)
                ans-=1;
                else{
                    ans-=2;
                }
            }
            else{
                
                if(b[5] && b[6])ans-=2;
                if(b[5] && b[6]==0){
                if(b[8]==0 && b[9]==0 && b[7]==0)
                ans-=1;
                else ans-=2;
                }
                if(b[6] && b[5]==0){
                    if(b[3]==0 && b[2]==0 && b[4]==0)ans-=1;
                    else ans-=2;
                }
                if(b[5]==0 && b[6]==0 && b[4]==0 && b[7]==0){
                    
                    if((b[2] || b[3]) || (b[8] || b[9])){
                        ans-=1;
                    }
                    
                    
                }
                
                
            }
            
        }
        return ans;
        
    }
};