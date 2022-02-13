class Solution {
public:
    using p=pair<int,int>;
    static bool cmp(p& a,p& b){
        return a.first>b.first;
    }
    int minimumOperations(vector<int>& nums){
        
        unordered_map<int,int> m1,m2;
        
        int n=nums.size();
        
        if(n==1)return 0;
        
        for(int i=0;i<n;i++)
        {   
            if(i%2==0){
                m1[nums[i]]++;
              
            }
            else
            {
                  m2[nums[i]]++;  
           
            }      
        }        
        
        vector<pair<int,int>> v,u;
        
        for(auto i:m1){
            v.push_back({i.second,i.first});
        }
        for(auto i:m2){
            u.push_back({i.second,i.first});
        }
        
        sort(v.begin(),v.end(),cmp);
        sort(u.begin(),u.end(),cmp);
        

        
        int i=0;
        int j=0;
        
        while(i<v.size() && j<u.size()){
            
            if(v[i].second!=u[j].second){
                return n-v[i].first-u[j].first;
            }
            
            if(v[i].first>u[j].first){
                
                j++;
                if(j==u.size()){
                    return n-v[i].first;
                }
                
                
                
            }
            else{
                i++;
                
                if(i==v.size()){
                    return n-u[j].first;
                }
            }
            
            
        }
        
     return 0;
    }
};