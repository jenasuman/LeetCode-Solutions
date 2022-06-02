class MyCalendar {
    vector<pair<int,int>> v;
public:
    MyCalendar() {
        
    } 
    bool book(int ns, int ne) {
        
        for(auto [s,e]:v){
          
          
            if(!(ns>=e || ne<=s))return false;
            
            
            
        }
        
        v.push_back({ns,ne});
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */