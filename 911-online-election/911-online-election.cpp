class TopVotedCandidate {
       unordered_map<int,int> m;
       unordered_map<int,int> w;
       vector<int> times;
       int n;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
       
        int currWinner=-1;
        n=persons.size();
        for(int i=0;i<n;i++){
            
            m[persons[i]]++;
            if(currWinner==-1)currWinner=persons[i];
            else if(m[currWinner]==m[persons[i]])currWinner=persons[i];
            else if(m[currWinner]<m[persons[i]])currWinner=persons[i];
            w[times[i]]=currWinner;
        }
        
        
        this->times=times;
    }
    
    int q(int t) {
        
        int i=lower_bound(times.begin(),times.end(),t)-times.begin();
        
        if(i!=n && times[i]==t)return w[t];

        // cout<<w[times[i-1]];
        return w[times[i-1]];
        
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */