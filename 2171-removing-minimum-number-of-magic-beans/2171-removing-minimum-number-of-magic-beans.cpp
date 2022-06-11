class Solution {
public:
    long long minimumRemoval(vector<int>& v) {
        
int n = v.size();
        sort(v.begin(), v.end());
        if(n == 1) return 0;    
		
		// Calculating prefix and suffix sums
        vector<long long> pref(n, 0), suf(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(i == 0) 
                pref[i] = v[i];
            else 
                pref[i] = pref[i-1] + v[i];
        }
        for(int i = n-1; i >= 0; i--)
        {
            if(i == n-1) 
                suf[i] = v[i];
            else 
                suf[i] = suf[i+1] + v[i];
        }
       
		long long res = 1e13;
       
		// Required calculation for minimum number of operations
		for(int i = 0; i < n; i++)
        {
            long long prevSum = ((i == 0) ? 0 : pref[i-1]);
            long long aheadSum = suf[i];
            long long temp = prevSum + aheadSum - (long long)(n-i)*(long long)v[i];
            res = min(res, temp);
        }
        return res;

        
    }
};