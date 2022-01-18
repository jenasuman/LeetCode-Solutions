class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int m) {
        
        int n=flowerbed.size();
        
        int countbegin=0;
        
        int i=0;
        
        while(i<n && flowerbed[i]==0){
            countbegin++;
            i++;
        }
        
        if(countbegin==1 && n==1){
            return true;
        }
        
        int count=0;
        
        if(i!=n)
        count+=(countbegin>0)?ceil((countbegin-1)/2.0):0;
        else{
            count+=ceil((countbegin)/2.0);
        }
        
        
        
        int countMiddle=0;
        
        for(;i<n;i++){
            
            if(flowerbed[i]==1){
                count+=(countMiddle>0)?ceil((countMiddle-2)/2.0):0;
                countMiddle=0;
            }
            else{
                countMiddle++;
            }
            
            
        }
        
             count+=(countMiddle>0)?ceil((countMiddle-1)/2.0):0;
        
         
        return count>=m;
    }
};