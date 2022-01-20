class Solution {
public:
    bool isPossible(vector<int>& piles, int h,int mid){
        
        int count=0;
        int i=0;
        
        int n=piles.size();
        
        for(int i=0;i<n;i++){
            
            count+=(piles[i]%mid==0)?piles[i]/mid:piles[i]/mid+1;
            
        }
        
        return count<=h;
        
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int hi=1e9;
         int lo=1;
      
      
         int ans=-1;
        while(hi-lo>1){
            
            int mid=lo+(hi-lo)/2;
            
            if(isPossible(piles,h,mid)){

                hi=mid;
            }
            else lo=mid+1;
            
        }
        
        return isPossible(piles,h,lo)?lo:hi;
    }
};