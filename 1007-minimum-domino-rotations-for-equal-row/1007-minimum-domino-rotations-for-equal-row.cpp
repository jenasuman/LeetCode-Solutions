class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        unordered_map<int,int> m;
        
        int n=tops.size();
        

        
        for(auto i:tops){
            m[i]++;
        }
        for(auto i:bottoms){
            m[i]++;
        }
        
        vector<int> v;
        
        for(auto [x,count]:m){
            
            if(count>=n){
                v.push_back(x);
            }
            
        }
        // O(6*N)
        int ans=INT_MAX;
      for(int num=1;num<=6;num++){  
          int count1=0;
          int count2=0;
          bool flag=true;
        for(int i=0;i<n;i++){
            //O(N)
            if(tops[i]!=num && bottoms[i]!=num){
                flag=false;
                break;
            }
            if(tops[i]!=num && bottoms[i]==num ){
                count1++;
            }
            if(bottoms[i]!=num && tops[i]==num){
                count2++;
            }
    
            
        }
          
          if(flag)ans=min({ans,count1,count2});
          
          
      }
        
       return ans==INT_MAX?-1:ans; 
    }
};