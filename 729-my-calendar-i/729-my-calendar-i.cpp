class MyCalendar {
   map<int,int> m;
public:
    MyCalendar() {
        
    } 
    bool book(int ns, int ne) {
        
        auto it=m.upper_bound(ns);
        
        if(it!=m.end() && !(it->first>=ne)) return false;
        if(it!=m.begin() && !(prev(it)->second<=ns))return false;
        
        m[ns]=ne;
        
        return true;
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */