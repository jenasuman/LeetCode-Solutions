class MyCalendarThree {
    map<int,int> m;
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        m[start]+=1;
        m[end]-=1;
        
        int countEvents=0;
        int ans=0;
        
        for(auto [time,value]:m){
            
            countEvents+=value;
            
            ans=max(countEvents,ans);
            
            
        }
        return ans;
        
        
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */