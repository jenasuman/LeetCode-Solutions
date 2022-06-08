class ProductOfNumbers {
     vector<long long int> v;
     vector<int> zeros;
     long long int curr; 
public:
    ProductOfNumbers() {
        curr=1;
    }
    
    void add(int num) {
        
        if(num==0){
            
            int zeroCount=1;
            
            if(zeros.size()!=0){
                zeroCount+=zeros.back();
                
            }
          zeros.push_back(zeroCount);
          curr=1;
          v.push_back(0);  
            
        }
        else{
            
            curr*=num;
            
            v.push_back(curr);
            
            int zeroCount=0;
            
            if(zeros.size()!=0){
                zeroCount+=zeros.back();
                
            }
            zeros.push_back(zeroCount);
            
            
            
        }
        
    }
    
    int getProduct(int k) {
        
        
      
        long long int res;
        
        int n=zeros.size();
        
       
        
        int countBack=zeros[n-1];
        
        if((n-k-1)<0){
            if(zeros[n-1]>0)return 0;
            
            return v[n-1];
        }
        
        int countfront=zeros[n-k-1];
        
        if(countBack>countfront)return 0;
        
        res=v[n-1];
        
        if(v[n-k-1]!=0){
            res/=v[n-k-1];
        }
        
        return res;
        
        
        
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */