class Solution {
public:
int maxArea(int hi, int wi, vector<int>& horizontalCuts, vector<int>& verticalCuts) 
{
      
    
       horizontalCuts.push_back(hi);
       verticalCuts.push_back(wi);
    
       int n=size(horizontalCuts);
       int m=size(verticalCuts);
       int mod=1e9+7;
    
       sort(begin(horizontalCuts),end(horizontalCuts));
       sort(begin(verticalCuts),end(verticalCuts));
       long long int w=(horizontalCuts[0]%mod);
       long long int h=(verticalCuts[0]%mod);
      
       // cout<<h<<" "<<w<<"\n";
       
       int currLen;
    
       for(int i=1;i<n;i++){
           currLen=(horizontalCuts[i]-horizontalCuts[i-1]+mod)%mod;
           if(currLen>w)w=(currLen%mod);
           // w=max(currLen,w);
       }
       
        for(int i=1;i<m;i++){
           currLen=(verticalCuts[i]-verticalCuts[i-1]+mod)%mod;
           if(currLen>h)h=(currLen%mod);
          // h=max(currLen,h);
       }
      
       // cout<<h<<" "<<w<<"\n";
    
       return ((h)*(w))%mod;
    
    
    
}
};