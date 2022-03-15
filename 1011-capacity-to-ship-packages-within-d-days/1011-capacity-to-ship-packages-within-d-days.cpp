class Solution {
public:
    bool isPossible(int minWeight,int days,vector<int>& weights){
        
        int cnt=1;
        int currWeight=0;
        
        for(int i=0;i<weights.size();i++){
          
            currWeight+=weights[i];
            
            if(currWeight>minWeight){
                cnt++;
                currWeight=weights[i];
            }
            
            if(cnt>days)return false;
             
            
        }
        
        return true;
        
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=INT_MIN;
        int high=0;
        int sum=0;
        
        int n=weights.size();
        
        for(int i=0;i<n;i++){
            low=max(low,weights[i]);
            sum+=weights[i];
        }
        int ans=-1;
        high=sum;
        while(low<=high){
            
            int mid=low+(high-low)/2;
            
            if(isPossible(mid,days,weights)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
            
            
            
            
        }
        
        return ans;
    }
};