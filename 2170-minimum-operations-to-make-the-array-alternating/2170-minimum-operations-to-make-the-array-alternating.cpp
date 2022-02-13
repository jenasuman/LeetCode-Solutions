class Solution {
public:
    using p=pair<int,int>;
    int minimumOperations(vector<int>& nums){
        
      
        
        unordered_map<int,int> m1,m2;
        int countEven=0;
        int countOdd=0;
        int n=nums.size();
        
        if(n==1)return 0;
        
        if(n==2 && nums[1]!=nums[0])return 0;
        
        
        for(int i=0;i<n;i++)
        {   
            if(i%2==0){
                m1[nums[i]]++;
                countEven++;
            }
            else
            {
                  m2[nums[i]]++;  
                  countOdd++;
            }      
        }        
        
        priority_queue<p> evenPlaces,oddPlaces;
        
        for(auto i:m1){
            evenPlaces.push({i.second,i.first});
        }
        for(auto i:m2){
            oddPlaces.push({i.second,i.first});
        }
        
        if(evenPlaces.top().second!=oddPlaces.top().second){
            return n-evenPlaces.top().first-oddPlaces.top().first;
        }
        else{
            
            if(evenPlaces.top().first>oddPlaces.top().first){
                
                oddPlaces.pop();
                
                if(oddPlaces.empty()){
                    return n-evenPlaces.top().first;
                }
                else{
                    return n-evenPlaces.top().first-oddPlaces.top().first;
                }
                
                
            }
            
            else{
                evenPlaces.pop();
                
                if(evenPlaces.empty()){
                    return n-oddPlaces.top().first;
                }
                else{
                    return n-evenPlaces.top().first-oddPlaces.top().first;
                }
                
            }
            
            
            
            
        }
        
        
    }
};