class MyCalendarTwo {
    vector<pair<int,int>> bookings;
    vector<pair<int,int>> doubleBookings;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        for(auto [s,e]:doubleBookings){
            
            if(max(s,start)<min(e,end))return false;
            
        }
        
        for(auto [s,e]:bookings){
            
            if(max(s,start)<min(e,end)){
                int newStart=max(s,start);
                int newEnd=min(e,end);
                doubleBookings.push_back({newStart,newEnd});
            }
            
            
        }
        
        
        
        bookings.push_back({start,end});
        
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */