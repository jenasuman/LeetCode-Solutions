class Solution {
public:
    void nextPermutation(vector<int>& nums) {
         // next_permutation(nums.begin(),nums.end());
         //Generate all permutations put them in a vector sort the vector and find the next permutation from the array
        //Brute force method complexity
        // N!*N as there are N! orders and N is the length of every array
        
        // 1 1 5
        // 1 5 1
        
        // 1 3 5 4 2
        // 1 4 5 3 2
        // 1 4 2 3 5
        
//         Algo
//             i) a[i]<a[i+1]  index1=1;
//             ii) Traverse from back
//                 a[index2]>a[index1] index=3
//             iii) swap(a[index1],a[index2])
//              iv) reverse(index1+1,last)
           // intuition lies in dictionary order
        int n=nums.size(),k;
        
        for(k=n-2;k>=0;k--){
            if(nums[k]<nums[k+1]){
                break;
            }
        }
        if(k<0){
            reverse(nums.begin(),nums.end());
        }
        else{
            
            for(int i=n-1;i>=0;i--){
                if(nums[i]>nums[k]){
                    swap(nums[i],nums[k]);
                    break;
                }
            }
            
            reverse(nums.begin()+k+1,nums.end());
            
            
        }
    }
};