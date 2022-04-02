class Solution {
public:
    bool palin(string s,int start,int end)
    {
        while(start<=end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
                return false;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n=s.size();
        int start=0;
        int end=n-1;
        while(start<end)
        {
            if(s[start]==s[end])
            {
                start++;
                end--;
            }
            else
            {
                return (palin(s,start+1,end) || palin(s,start,end-1)); // goes to check the two possible removal conditions
            }
        }
        return true;
    }
};