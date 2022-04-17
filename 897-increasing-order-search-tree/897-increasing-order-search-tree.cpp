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
      TreeNode* ans;
    void solve(TreeNode* root){
        
        if(root==NULL)return;
        
        solve(root->left);
        TreeNode* temp=new TreeNode(root->val);
        if(ans==NULL)ans=temp;
        else{
            TreeNode* temp1=ans;
            while(temp1 && temp1->right){
                temp1=temp1->right;
            }
            temp1->right=temp;
        }
        
         solve(root->right);
        
        
    }
    TreeNode* increasingBST(TreeNode* root) {
        // TreeNode* ans;
        // ans=NULL;
        ans=NULL;
        solve(root);
        
        return ans;
        
        
       
    }
};