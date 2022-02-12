class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> myset;
        bool isPresent=false;
        
        for(auto word:wordList){
            if(endWord.compare(word)==0){
                isPresent=true;
            }
            myset.insert(word);
        }
        if(isPresent==false)return 0;
        
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        
        
        while(!q.empty()){
            
            depth+=1;
            
            int n=q.size();
            
            while(n--){
                
                string curr=q.front();
                
                q.pop();
                
                for(int i=0;i<curr.size();i++){
                    
                    string temp=curr;
                    
                    for(char c='a';c<='z';c++){
                        
                        temp[i]=c;
                        
                        if(curr.compare(temp)==0)continue;
                        if(temp.compare(endWord)==0){
                            return depth+1;
                        }
                        if(myset.find(temp)!=myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                        
                        
                    }
                    
                    
                    
                    
                }
                
                
                
                
                
                
            }
            
            
            
            
        }
        
        //Complexity O(n*26*1*W)
        
        
        
        return 0;
        
        
    }
};