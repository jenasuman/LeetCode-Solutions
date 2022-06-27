class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        
        int n=cardPoints.size();
        int r=n-k;
        int total=accumulate(begin(cardPoints),end(cardPoints),0);
        
        
        if(r==0)return total;
        
        int i=0;
        int j=0;
        
        int minSumArray=INT_MAX;
        int currSum=0;
        
        for(;i<n;i++){
            
             currSum+=cardPoints[i];
              
             if((i-j+1)==r){
                 minSumArray=min(currSum,minSumArray);
                 currSum-=cardPoints[j];
                 j++;
             }
            
       }
        
        
       return total-minSumArray; 
        
        
    }
};