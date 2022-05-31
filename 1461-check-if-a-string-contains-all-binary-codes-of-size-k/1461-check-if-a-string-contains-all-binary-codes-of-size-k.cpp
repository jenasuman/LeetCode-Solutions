class Solution {
public:
    bool hasAllCodes(string s, int k) {
        
        int n=s.size();
        unordered_map<int,int> m;
        
        for(int i=0;i<=n-k;i++){
            
            int j=i+k-1;
            
            int num=0;
            int p=0;
            
            while(j>=i){
                
                num=num+(s[j]-'0')*(pow(2,p));
                p++;
                j--;
                
                
            }
            
            
            m[num]++;
            
            
        }
        
        for(int i=0;i<pow(2,k);i++){
            if(m.find(i)==m.end())return false;
        }
        return true;
        
    }
};