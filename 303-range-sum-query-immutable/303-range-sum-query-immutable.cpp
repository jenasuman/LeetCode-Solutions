class NumArray {
    vector<int> prefix;
    int n;
public:
    NumArray(vector<int>& nums) {
        if(nums.size()>0){
          n=nums.size();
          prefix.resize(n,0);
          prefix[0]=nums[0];  
          for(int i=1;i<n;i++){
              prefix[i]=prefix[i-1]+nums[i];
          }  
          // for(auto c:prefix){
          //     cout<<c<<" ";
          // }  
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0)
        return prefix[right];
        return (prefix[right]-prefix[left-1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */