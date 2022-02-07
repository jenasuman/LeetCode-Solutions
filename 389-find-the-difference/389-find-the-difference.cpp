class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> m;
        
        for(auto c:s)m[c]++;
        char ans;
        for(auto c:t){
            if(m.find(c)==m.end()){
                ans=c;
                break;
            }
            else if(m[c]==0){
                ans=c;
                break;
            }
            m[c]--;
        }
        return ans;
    }
};