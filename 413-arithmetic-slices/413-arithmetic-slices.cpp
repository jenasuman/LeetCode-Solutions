class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        
           unordered_map<int,int> m;
           
           int n=A.size();
           int diff;   
           int ans=0;
           int prev=0;
           for(int i=1;i<n;i++){
               
               diff=A[i]-A[i-1];
               
               if(i==1 || m[i-1]==diff){
                   if((i-prev)>=2){
                       ans+=((i-prev)-1);
                   }
               }
               else{
                   prev=(i-1);
               }
               
               m[i]=diff;
               
               
           }
         
        return ans;
        
        
    }
};