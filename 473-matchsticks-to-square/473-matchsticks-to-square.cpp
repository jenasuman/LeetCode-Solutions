class Solution {
public:
    
    int n;
    using ll=long long int;
    
    bool f(int j,ll prev,ll k,int sides,vector<int>& ma,vector<int>& vis){
        

        if(sides==0)return true;
        

        
        if(prev==k){
            return f(0,0,k,sides-1,ma,vis);
        }
    
        for(int i=j;i<n;i++){
            
            if(vis[i]==0){
                
                if(prev+ma[i]<=k){
                    
                    vis[i]=1;
                    
                    if(f(i+1,ma[i]+prev,k,sides,ma,vis))return true;
                    
                    vis[i]=0;
                    
                    
                }
            
                
                
                
                
            }
            
            
            
            
        }
        
        
        return false;
        
    }

    bool makesquare(vector<int>& ma) {
        
        
        n=ma.size();
        
        if(n<=3)return false;
       
        ll sum=0;
        
        for(auto i:ma)sum+=i;
        
        if(sum%4!=0)return false;
        
        ll k=sum/4;
        
        if(n==4){
            
            if(k==ma[0])return true;
            else return false;
            
        }

        vector<int> vis(n,0);
        
        return f(0,0,k,4,ma,vis);
        
        
        
    }
};