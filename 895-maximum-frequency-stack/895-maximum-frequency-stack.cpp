class FreqStack {
    typedef pair<int,int> p;
    priority_queue<p> pq;
    unordered_map<int,int> freqCount;
    unordered_map<int,int> inTime;
    int count;
public:
    FreqStack() {
         count=0;
    }
    
    void push(int val) {
        freqCount[val]++;
        inTime[count]=val;
        pq.push({freqCount[val],count});
        count++;
    }
    
    int pop() {
        p t=pq.top();
        pq.pop();
        
        int time=t.second;
        int val=inTime[time];
        
        freqCount[val]--;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */