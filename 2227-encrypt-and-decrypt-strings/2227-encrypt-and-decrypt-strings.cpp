class Encrypter {
     unordered_map<char, string> keyVal;        
    unordered_map<string, int> permitted;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int n=keys.size();
        
        for(int i=0;i<n;i++){
            keyVal[keys[i]]=values[i];
        }
        
        for(auto s:dictionary){
            string g="";
            for(auto c:s){
                g+=keyVal[c];
            }
            permitted[g]++;
            
        }
        
        
        
    }
    
    string encrypt(string word1) {
        string temp="";
        
        for(auto c:word1){
            temp+=keyVal[c];
        }
        
        return temp;
        
    }
    
    int decrypt(string word2) {
        return permitted[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */