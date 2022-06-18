class MyCircularDeque {
    vector<int> v;
    int size;
    int i;
    int j;
public:
    MyCircularDeque(int k) {
        size=k;
        i=1001;
        j=1001;
        v.resize(3001);
    }
    
    bool insertFront(int value) {
        if(!isFull()){
            
            if(i==j){
                v[j]=value;
                j++;
            }
          
            v[i]=value;
            i--;
            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(!isFull()){
            if(i==j){
                v[i]=value;
                i--;
            }
            v[j]=value;
            j++;
            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(!isEmpty()){
            if((j-i-1)==1){
                j--;
            }
            i++;
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
       if(!isEmpty()){
            if((j-i-1)==1){
                i++;
            }
            j--;
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(!isEmpty()){
            return v[i+1];
        }
        return -1;
    }
    
    int getRear() {
        if(!isEmpty()){
            return v[j-1];
        }
        return -1;
    }
    
    bool isEmpty() {
        // cout<<i<<" "<<j<<" ";
          return (i==j);   
    }
    
    bool isFull() {
           
         // cout<<j-i-1<<" ";    
          return (j-i-1)==size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */