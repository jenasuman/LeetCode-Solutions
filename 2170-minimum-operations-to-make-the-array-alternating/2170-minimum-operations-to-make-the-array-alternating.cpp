class Solution {
        using p=pair<int,int>;
    static bool cmp(p& a,p& b){
        return a.first>b.first;
    }
public:
    int minimumOperations(vector<int>& nums) {
        
        unordered_map<int,int> me;
        unordered_map<int,int> mo;
        int n=nums.size();
        int countEven=0;
        int countOdd=0;
        for(int i=0;i<n;i++){
            
            if(i%2==0){
                me[nums[i]]++;
                countEven++;
            }
            else{
                mo[nums[i]]++;
                countOdd++;
            }
            
        }
        vector<pair<int,int>> vo,ve; 
        for(auto i:mo){
            vo.push_back({i.second,i.first});
        }
         for(auto i:me){
            ve.push_back({i.second,i.first});
        }
        
        sort(begin(ve),end(ve),cmp);
        sort(begin(vo),end(vo),cmp);
            
        
        int l=ve.size();
        int m=vo.size();
        int ans=INT_MAX;
        for(int i=0;i<2 && i<l;i++){
            
            
            for(int j=0;j<2 && j<m;j++){
                
                if(ve[i].second==vo[j].second)continue;
                
                ans=min(ans,n-ve[i].first-vo[j].first);
                
                
                
            }
            
            
            
            
        }
        
        if(ans==INT_MAX){
            ans=min(countEven,countOdd);
        }
        
         return ans;    
        
    }
};