class Solution {
public:
  
    int numRescueBoats(vector<int>& people, int limit) {
      int n=people.size();
      
      sort(people.begin(),people.end());
       
      int boat=0; 
      int i=0;
      int j=n-1;
      int currWeight=0;  
      while(i<=j){
          
       if(people[i]+people[j]<=limit){
         
           i++;
       }
         j--;
         boat++; 
          
          
      }  
        
        
        return boat;
        
    }
};