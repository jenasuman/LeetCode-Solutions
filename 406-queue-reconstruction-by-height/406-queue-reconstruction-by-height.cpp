class Solution {
    static bool comp(vector<int>& a,vector<int>& b){
        
        if(a[1]<b[1]){
            return a[0]<b[0];
        }
        if(a[1]==b[1]){
            return a[0]>b[0];
        }
        
        return a[1]<b[1];
    }
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
     
        sort(begin(people),end(people));
      
        // return people;
      
//         for(auto v:people){
            
//             cout<<"["<<v[0]<<" "<<v[1]<<"]"<<" ";
            
//         }
//         cout<<endl;
        int n=people.size();
          
        vector<vector<int>> ans(n);
        vector<int> vis(n,0);
        
        for(int i=n-1;i>=0;i--){
               
                int j=people[i][1];
                

                   int curr=people[i][0];
                    while(j<n && vis[j]!=0){
                        
                        if(ans[j][0]!=curr)
                        swap(ans[j],people[i]);
                        
                        // auto v=ans[j];
                        // ans[j]=people[i];
                        // people[i]=v;
                        j++;
                        
                    }
                    
                    
            
            
                ans[j]=people[i];
                vis[j]=1;
            

            }
        
        return ans;
        
        
    }
};