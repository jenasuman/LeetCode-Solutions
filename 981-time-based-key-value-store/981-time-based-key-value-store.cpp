class TimeMap {
    
    unordered_map<string,vector<int>> m;
    unordered_map<int,string> ref;
    
    
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].push_back(timestamp);
        ref[timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        
         if(m.find(key)==m.end())return "";

        
         int i=upper_bound(begin(m[key]),end(m[key]),timestamp)-begin(m[key]);
         if(i==0)return "";
         return ref[m[key][i-1]];
          
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */