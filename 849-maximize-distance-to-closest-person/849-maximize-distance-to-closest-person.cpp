class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
      
        int n=seats.size();
        
        vector<int> right(n,0);
        
        vector<int> left(n,0);
        
        if(seats[0]==0){
            left[0]=INT_MAX;
        }
        
        for(int i=1;i<n;i++){
            
            if(seats[i]==1)continue;
            
            if(seats[i-1]==1){
                left[i]=1;
            }
            else{
                
                if(left[i-1]==INT_MAX){
                    left[i]=left[i-1];
                }
                else{
                    left[i]=left[i-1]+1;
                }
                
            }
            
            
        }
        
        if(seats[n-1]==0){
            right[n-1]=INT_MAX;
        }
     for(int i=n-2;i>=0;i--){
            if(seats[i]==1)continue;
            if(seats[i+1]==1){
                right[i]=1;
            }
            else{
                
                if(right[i+1]==INT_MAX){
                    right[i]=right[i+1];
                }
                else{
                    right[i]=right[i+1]+1;
                }
                
            }
            
            
        }
        
        int ans=INT_MIN;
        int t;
        
        for(int i=0;i<n;i++){
            
            t=min(right[i],left[i]);
            
            ans=max(t,ans);
            
        }
        
        return ans;
        
        
    }
};