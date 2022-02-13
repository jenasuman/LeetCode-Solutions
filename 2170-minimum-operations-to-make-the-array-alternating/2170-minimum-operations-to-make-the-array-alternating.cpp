class Solution {
public:
    using p=pair<int,int>;
    static bool cmp(p& a,p& b){
        return a.first>b.first;
    }
    int minimumOperations(vector<int>& nums){
        
     
        unordered_map<int,int> m1,m2;
        int countEven=0;
        int countOdd=0;
        int n=nums.size();
        if(n==1)return 0;
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
        
        vector<pair<int,int>> v,u;
        
        for(auto i:m1){
            v.push_back({i.second,i.first});
        }
        for(auto i:m2){
            u.push_back({i.second,i.first});
        }
        
        sort(v.begin(),v.end(),cmp);
        sort(u.begin(),u.end(),cmp);
        
        int ans=INT_MAX;
        
        for(int i=0;i<2 && i<v.size();i++){
            for(int j=0;j<2 && j<u.size();j++){
                if(v[i].second==u[j].second)continue;
                
                int temp=countEven-v[i].first+countOdd-u[j].first;
                
                ans=min(temp,ans);
            }
        }
        if(ans==INT_MAX)ans=min(countEven,countOdd);
        return ans;
    }
};