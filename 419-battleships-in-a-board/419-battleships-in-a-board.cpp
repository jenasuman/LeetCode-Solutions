class Solution {
public:
    int countBattleships(vector<vector<char>>& b) {
         
        int count=0;
        int n=b.size();
        int m=b[0].size();
        
        for(int i=0;i<n;i++){
            if(b[i][0]=='X'){
                    count++;
            }
            for(int j=1;j<m;j++){
                
                if(b[i][j-1]=='.' && b[i][j]=='X'){
                    
                    count++;
                    
                }

                
                
            }
            
            
        }
        int res;
        for(int i=0;i<m;i++){
            res=0;
            if(b[0][i]=='X'){
                count++;
                res++;
            }
            
            for(int j=1;j<n;j++){
                
                if(b[j-1][i]=='X' && b[j][i]=='X'){
                    res++;
                }
                if(b[j][i]=='.'){
                    // cout<<count<<" "<<res<<"\n";
                    count-=res;
                    res=0;
                }
                if(b[j-1][i]=='.' && b[j][i]=='X'){
                    count++;
                    res++;
                }
                
            }
            count-=res;
            
        }
        
        
        return count;
        
        
    }
};