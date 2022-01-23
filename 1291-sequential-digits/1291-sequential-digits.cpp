class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        set<int> s;
        s.insert(1);
        s.insert(12);
        s.insert(23);
        s.insert(34);    
        s.insert(45);
        s.insert(56);
        s.insert(67);
        s.insert(78);
        s.insert(89);
        s.insert(123);
        s.insert(234);
        s.insert(345);
        s.insert(456);
        s.insert(567);
        s.insert(678);
        s.insert(789);
        s.insert(1234);
        s.insert(2345);
        s.insert(3456);
        s.insert(4567);
        s.insert(5678);
        s.insert(6789);
        s.insert(12345);
        s.insert(23456);
        s.insert(34567);
        s.insert(45678);
        s.insert(56789);
        s.insert(123456);
        s.insert(234567);
        s.insert(345678);
        s.insert(456789);
        s.insert(12345678);
        s.insert(23456789);
        s.insert(1234567);
        s.insert(2345678);
        s.insert(3456789);
        s.insert(123456789);
        
    vector<int> ans;
        
        for(auto i:s){
            if(i>=low && i<=high)ans.push_back(i);
        }
        
        return ans;
            
            
        
        
    }
};