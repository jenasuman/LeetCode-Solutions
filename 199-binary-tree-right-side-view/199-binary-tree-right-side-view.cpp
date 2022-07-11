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
    vector<int> rightSideView(TreeNode* root) {
        
        //Level order traversal
        
        if(root==NULL)return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> ans;
        
        while(!q.empty()){
            
            int n=q.size();
            
            for(int i=1;i<=n;i++){
                TreeNode* currNode=q.front();
                q.pop();
                if(i==n){
                    ans.push_back(currNode->val);
                }
                
                if(currNode->left){
                    q.push(currNode->left);
                }
                 if(currNode->right){
                    q.push(currNode->right);
                }
                
                
                
            }
            
            
            
            
        }
        
        return ans;
        
        
    }
};