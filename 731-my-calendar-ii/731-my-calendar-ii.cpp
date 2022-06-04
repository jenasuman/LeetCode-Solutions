class MyCalendarTwo {
    map<int,int> m;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        
        int countEvents=0;
        
        m[start]+=1;
        m[end]+=-1;
        
        for(auto [time,value]:m){
            
            countEvents+=value;
            
            if(countEvents>2){
                m[start]-=1;
                m[end]+=1;
                return false;
            }
            
        }
        
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */