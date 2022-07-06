// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        
        unordered_map<char,int> mp;
        for(auto c:p)mp[c]++;
        int n=s.size();
        int m=p.size();
        int count=mp.size();
        int j=0;
        int l=INT_MAX;
        string ans="-1";
        for(int i=0;i<n;i++){
            
            if(mp.find(s[i])!=mp.end()){
                
               mp[s[i]]--;
               
               if(mp[s[i]]==0){
                  count--;
               }
             }
             
            while(count==0){
                 
                  if(l>(i-j+1)){
                       l=i-j+1;
                       ans=s.substr(j,l);  
                   } 
                  if(mp.find(s[j])!=mp.end()){
                      mp[s[j]]++;
                     if(mp[s[j]]==1)count++;
                  }
                //   cout<<j<<"\n";
                  j++; 
                   
             }
            
            
            
        }
        
        
        return ans;
        
        
        
        
        
    }
};

// { Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends