class UndergroundSystem {
    unordered_map<int,pair<string,int>> m;
    unordered_map<string,pair<int,int>> s;
public:
    UndergroundSystem(){
     
    }
    
    void checkIn(int id, string stationName, int t) {
    
             m[id]={stationName,t};
             
    }
    
    void checkOut(int id, string stationName, int t) {
           string startStation=m[id].first;
           int startTime=m[id].second;
           string key=startStation+"#"+stationName;
           t=t-startTime;
           if(s.find(key)==s.end()){
                s[key]={t,1};
           }
           else{
               s[key].first+=t;
               s[key].second++;
           }
    }
    
    double getAverageTime(string startStation, string endStation) {
         string key=startStation+"#"+endStation;
         double t=s[key].first;
         double c=s[key].second;
         return (t/c);
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */