class Solution {
public:
    int countPairs(vector<int>& arr) {
        unordered_map<int,int> mp;
        long long ans = 0;
        for(auto a : arr)
        {
            for(int i=1;i<=pow(2,21);i*=2)
            {
                if(mp.count(i-a))
                {
                    ans += mp[i-a];
                }
            }
            mp[a]++;
        }
        return ans % (int)(1e9 + 7);
    }
};