class Solution {
public:
    vector<string>v = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void solve(int index,string& digits,string& temp,vector<string>& ans){
        if(index==digits.size()){
            ans.push_back(temp);
            return;
        }
        
        for(auto i:v[digits[index]-'0']){
            
            temp.push_back(i);
            solve(index+1,digits,temp,ans);
            temp.pop_back();
            
            
        }
        
        
        
    }
    vector<string> letterCombinations(string digits) {
          
        if(digits.size()==0)return {};
        vector<string> ans;
        string temp="";
        
        solve(0,digits,temp,ans);
        return ans;
    }
};