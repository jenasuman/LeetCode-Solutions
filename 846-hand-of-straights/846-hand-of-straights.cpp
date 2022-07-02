class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        int n=hand.size();
        if(n%groupSize!=0){
            return false;
        }
        
        // sort(begin(hand),end(hand));
        
        map<int,int> m;
        
        
        for(int i=0;i<n;i++){
            
            
            m[hand[i]]++;
            
            
        }
        
        
        for(auto i:m){
            int curr=i.first;
            int count=i.second;
            
            while(count){
                
                int k=1;
                int element=curr;
                count--;
                cout<<element<<" ";
                while(k<groupSize){
                    
                   element++;
                    
                   if(m.find(element)==m.end()){
                       return false;
                   } 
                   // cout<<element<<" ";
                   m[element]--;
                   if(m[element]==0){
                       m.erase(element);
                   } 
                   k++; 
                    
                }
                
                
                cout<<endl;
                
                
            }
            
            
            
        }
 
       return true;
        
    }
};