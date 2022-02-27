/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        
          if(root==NULL)return 0;
        
        int ans=0;
        
        queue<pair<TreeNode*,long long>> q;
        
        q.push({root,0});
        
        while(!q.empty()){
            
            int n=q.size();
            
            int imin=q.front().second;
            
            int first,last;
            
            for(int i=0;i<n;i++){
                
                long long currID=q.front().second-imin;
                
                TreeNode* curr=q.front().first;
                
                q.pop();
                
                if(i==0)first=currID;
                
                if(i==n-1)last=currID;
                if(curr->left){
                    q.push({curr->left,2*currID+1});
                }
                
                if(curr->right){
                    q.push({curr->right,2*currID+2});
                }
                
                
            }
            
            
            
            ans=max(ans,last-first+1);            
        }
      
        
        
        
        return ans;
    }
};