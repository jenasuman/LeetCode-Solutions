class AuthenticationManager {
    int timeToLive;
    map<string,long long int> m;
public:
    AuthenticationManager(int timeToLive) {
        this->timeToLive=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId]=currentTime+timeToLive;
    }
    
    void renew(string tokenId, int currentTime) {
        if(m.find(tokenId)!=m.end() && m[tokenId]>currentTime){
            m[tokenId]=currentTime+timeToLive;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for(auto i:m){
            if(i.second>currentTime){
                count++;
            }
           
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */