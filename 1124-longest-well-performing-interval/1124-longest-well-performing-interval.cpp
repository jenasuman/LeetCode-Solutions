class Solution {
public:
    int longestWPI(vector<int>& hours) {

        int n=hours.size();
        

        int ans=0;
        int sum=0;
        map<int,int> m;
        
        for(int i=0;i<n;i++){
             
            sum+=(hours[i]>8);
            sum-=(hours[i]<=8);
            
            
            if(sum>0){
                ans=max(ans,i+1);
            }
            else{
                
                if(m.find(sum-1)!=m.end()){
                    ans=max(ans,i-m[sum-1]);
                }
                
                
            }
            
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
            
            
        }
        
        
        return ans;
        
    }
};