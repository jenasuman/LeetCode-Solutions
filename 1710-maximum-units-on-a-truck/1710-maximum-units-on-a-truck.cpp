class Solution {
    
    static bool comp(vector<int>& a,vector<int>& b){
        
        return a[1]>b[1];
        
    }
    
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        sort(begin(boxTypes),end(boxTypes),comp);
        
        int ans=0;
        
        for(auto v:boxTypes){
            
            if(v[0]<=truckSize){
                truckSize-=v[0];
                ans+=(v[1]*v[0]);
            }
            else{

                ans+=(v[1]*truckSize);
                break;
            }
            
        }
        
        return ans;
    }
};